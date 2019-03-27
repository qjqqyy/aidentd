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
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* fake.h - OS's and user names    */
/* For extra fun, swap over the user_ids/os_types and 
   NUM_OS/NUM_USER bits. */

#define NUM_OS   118
#define NUM_USER 153

/* From RFC1340 - extra ones added just for the sake of it.   */

char *os_types[NUM_OS]={
	"AEGIS","LISP","SUN_OS_3.5","APOLLO",
	"LISPM","SUN_OS_4.0","AIX/370","LOCUS",
	"SWIFT","AIX-PS/2","MACOS","TAC","BS-2000",
	"MINOS","TANDEM","CEDAR","MOS","TENEX","CGW",
	"MPE5","TOPS10","CHORUS","MSDOS","TOPS20",
	"CHRYSALIS","MULTICS","TOS","CMOS","MUSIC",
	"TP3010","CMS","MUSIC/SP","TRSDOS","COS","MVS",
	"ULTRIX","CPIX","MVS/SP","UNIX","CTOS","NEXUS",
	"UNIX-BSD","CTSS","NMS","UNIX-V1AT","DCN","NONSTOP",
	"UNIX-V","DDNOS","NOS-2","UNIX-V.1","DOMAIN","NTOS",
	"UNIX-V.2","DOS","OS/DDP","UNIX-V.3","EDX","OS/2",
	"UNIX-PC","ELF","OS4","UNKNOWN","EMBOS","OS86",
	"UT2D","EMMOS","OSX","V","EPOS","PCDOS","VM","FOONEX",
	"PERQ/OS","VM/370","FUZZ","PLI","VM/CMS","GCOS","PSDOS/MIT",
	"VM/SP","GPOS","PRIMOS","VMS","HDOS","RMX/RDOS",
	"VMS/EUNICE","IMAGEN","ROS","VRTX","INTERCOM",
	"RSX11M","WAITS","IMPRESS","RTE-A","WANG","INTERLISP",
	"SATOPS","WIN32","IOS","SCO-XENIX/386","X11R3","IRIX",
	"SCS","XDE","ISI-68020","SIMP","XENIX","ITS","SUN",
	"FREEBSD","OPENBSD","NETBSD","LINUX","QNX","WINNT","MINIX",
	"SOLARIS"
	};

/* From watching the cartoons. */

char *userids[NUM_USER] = {
	"Bulbasaur","Ivysaur","Venusaur","Charmander","Charmeleon",
	"Charizard","Squirtle","Wartortle","Blastoise","Caterpie",
	"Metapod","Butterfree","Weedle","Kakuna","Beedrill",
	"Pidgey","Pidgeotto","Pidgeot","Rattata","Raticate",
	"Spearow","Fearow","Ekans","Arbok",
/* Pi...Pi...Pi....       */
	"Pikachu",
/* uuuuuuuuuuu!!!!!!!!!!! */
	"Raichu","Sandshrew","Sandslash","Nidoran_girl","Nidorina",
	"Nidoqueen","Nidoran_boy","Nidorino","Nidoking",
	"Clefairy","Clefable","Vulpix","Ninetales","Jigglypuff",
	"Wigglytuff","Zubat","Golbat","Oddish","Gloom","Vileplume",
	"Paras","Parasect","Venonat","Venomoth","Diglett","Dugtrio",
	"Meowth","Persian","Psyduck","Golduck","Mankey","Primeape",
	"Growlithe","Arcanine","Poliwag","Poliwhirl","Poliwrath",
	"Abra","Kadabra","Alakazam","Machop","Machoke","Machamp",
	"Bellsprout","Weepinbell","Victreebell","Tentacool",
	"Tentacruel","Geodude","Graveler","Golem","Ponyta",
	"Rapidash","Slowpoke","Slowbro","Magnemite","Magneton",
	"Farfetch'd","Doduo","Dodrio","Seel","Dewgong","Grimer",
	"Muk","Shellder","Cloyster","Gastly","Haunter","Gengar",
	"Onix","Drowzee","Hypno","Krabby","Kingler","Voltorb",
	"Electrode","Exeggcute","Exeggutor","Cubone","Marowak",
	"Hitmonlee","Hitmonchan","Lickitung","Koffing","Weezing",
	"Rhyhorn","Rhydon","Chansey","Tangela","Kangaskan",
	"Horsea","Seadra","Goldeen","Seaking","Staryu","Starmie",
	"Mr_Mime","Scyther","Jynx","Electabuzz","Magmar","Pinsir",
	"Tauros","Magikarp","Gyarados","Lapras","Ditto","Eevee",
	"Vaporeon","Jolteon","Flareon","Porygon","Omanite","Omastar",
	"Kabuto","Kabutops","Aerodactyl","Snorlax","Articuno",
	"Zapdos","Moltres","Dratini","Dragonair","Dragonite",
	"Mewtwo","Mew","Houou","Togepi"
};
