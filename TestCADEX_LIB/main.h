#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include "curve.h"

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

//float DLL_EXPORT Cube( float f );


#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
