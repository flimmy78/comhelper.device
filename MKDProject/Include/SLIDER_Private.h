/*
----------------------------------------------------------------------
File        : SLIDER_Private.h
Purpose     : SLIDER private header file
--------------------END-OF-HEADER-------------------------------------
*/

#ifndef SLIDER_PRIVATE_H
#define SLIDER_PRIVATE_H

#include "WM.h"
#include "WIDGET.h"
#include "SLIDER.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Object definition
*
**********************************************************************
*/
typedef struct {
  GUI_COLOR BkColor;
  GUI_COLOR Color;
  GUI_COLOR FocusColor;
} SLIDER_PROPS;

typedef struct {
  WIDGET Widget;
  SLIDER_PROPS Props;
  int Min, Max, v;
  int Flags;
  int NumTicks;
  I16 Width;
  #if GUI_DEBUG_LEVEL >1
    int DebugId;
  #endif
} SLIDER_Obj;

/*********************************************************************
*
*       Macros for internal use
*
**********************************************************************
*/
#if GUI_DEBUG_LEVEL >= GUI_DEBUG_LEVEL_CHECK_ALL
  SLIDER_Obj * SLIDER_h2p(SLIDER_Handle h);
  #define SLIDER_H2P(h) SLIDER_h2p(h)
  #define SLIDER_INIT_ID(p) p->DebugId = SLIDER_ID
#else
  #define SLIDER_H2P(h) (SLIDER_Obj *)GUI_ALLOC_h2p(h)
  #define SLIDER_INIT_ID(p)
#endif

/*********************************************************************
*
*       Public data (internal defaults)
*
**********************************************************************
*/
extern SLIDER_PROPS SLIDER__DefaultProps;

#endif

#endif
	 	 			 		    	 				 	  			   	 	 	 	 	 	  	  	      	   		 	 	 		  		  	 		 	  	  			     			       	   	 			  		    	 	     	 				  	 					 	 			   	  	  			 				 		 	 	 			     			 
