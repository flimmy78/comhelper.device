/*
----------------------------------------------------------------------
File        : GUIConf.h
Purpose     : Configures abilities, fonts etc.
----------------------------------------------------------------------
*/


#ifndef GUICONF_H
#define GUICONF_H

#define GUI_OS                    (0)  /* Compile with multitasking support */
#define GUI_SUPPORT_TOUCH         (1)  /* Support a touch screen (req. win-manager) */
#define GUI_SUPPORT_MOUSE         (0)  /* Support a mouse */
#define GUI_SUPPORT_UNICODE       (0)  /* Support mixed ASCII/UNICODE strings */
#define GUI_WINSUPPORT            1  /* Window manager package available */
#define GUI_ALLOC_SIZE            0x10000  /* Size of dynamic memory ... For WM and memory devices*/

#define GUI_DEFAULT_FONT          GUI_GetFontAddress(16)
#define WIDGET_USE_SCHEME_MEDIUM	1
/*********************************************************************
*
*         Configuration of available packages
*/

#define GUI_SUPPORT_MEMDEV        0  /* Memory devices available */
#define GUI_SUPPORT_AA            0  /* Anti aliasing available */

#endif  /* Avoid multiple inclusion */


	 	 			 		    	 				 	  			   	 	 	 	 	 	  	  	      	   		 	 	 		  		  	 		 	  	  			     			       	   	 			  		    	 	     	 				  	 					 	 			   	  	  			 				 		 	 	 			     			 
