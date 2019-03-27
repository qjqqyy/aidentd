/*  aidentd - a fake ident server

    Copyright (C) 2000 Afghan Hound Software

    Based on:
    
    nullidentd.c
    Copyright 1999 Brian Young <bayoung@acm.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA*/

/* aidentd.c - the server itself */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include "fake.h"
#include "version.h"

/* In seconds */
#define SESSION_TIMEOUT 20

#define MAX_RESPONSE 200
#define MAX_REQUEST  100
#define MAX_USERID   50

int get_random(int max)
{
  return (int)((1.0*rand()*max/(RAND_MAX+1.0)));
}

void init_random()
{
  struct timeval tv;
  long   wibble;
  gettimeofday(&tv,(struct timezone *)NULL);
  wibble = (int)tv.tv_sec + (int)tv.tv_usec;
  srand( (int)wibble );
} 

int write_response( int fd, char *response, int len )
{
  int		retval;
  int		byteswritten = 0;

  while( byteswritten < len ) 
    {
      retval = write( fd, response + byteswritten, len - byteswritten );
      if( retval <= 0 ) 
	{
	  /* error */
	  return 0;
	}
      byteswritten += retval;
    }

  /* success */
  return 1;
}

int read_request( int fd, char *request, int maxlen )
{
  int		retval;
  char	c;
  int		bytesread = 0;

  /* read until \n */
  while( bytesread < maxlen - 1 ) 
    {
      if( read( fd, &c, 1 ) != 1 ) 
	{
	  /* error */
	  return 0;
	}
      if( c == '\n' ) 
	{
	  /* end of line */
	  break;
	}
      
      request[bytesread] = c;
      bytesread += 1;
    }
  
  if( bytesread > 0 && request[bytesread-1] == '\r' ) 
    {
      /* strip trailing \r */
      bytesread -= 1;
    }
  /* null terminate */
  request[bytesread] = '\0';

  /* success */
  return 1;
}

void session_timeout( int foo )
{
  exit( 0 );
}

int main( int argc, const char *argv[] )
{
  char		c;
  int		infd;
  int		outfd;
  int		response_len;
  char		response[MAX_RESPONSE];
  char		request[MAX_REQUEST];

  if( ( getgid() == 0 ) || ( getuid() == 0 )  ) 
    {
      fprintf( stderr, "Group or user id is root, exitting.\n" );
      return 1;
    }


  infd = fileno( stdin );
  outfd = fileno( stdout );
  init_random();

  /* set the session timeout */
  signal( SIGALRM, session_timeout );
  alarm( SESSION_TIMEOUT );

  for( ;; ) 
    {
      /* read the request */
      if( !read_request( infd, request, MAX_REQUEST ) ) 
	{
	  /* error or timed out */
	  goto done;
	}

    /* format the response */
      response_len = snprintf( response, 
			       sizeof( response ), 
			       "%.20s : USERID : %s : %s\r\n", 
			       request, 
			       os_types[get_random(NUM_OS)],
			       userids[get_random(NUM_USER)]);

      /* send the line */
      if( !write_response( outfd, response, response_len ) ) 
	{
	  goto done;
	}
    }
  
 done:
  return 0;
}


