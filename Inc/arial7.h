/*
 * arial7.h
 *
 *  Created on: 16 ãðóä. 2012
 *      Author: vovan
 */

#ifndef ARIAL7_H_
#define ARIAL7_H_

/*******************************************************************************
* filename: /home/vovan/document/arial7.xml
* name: Arial7
* family: Arial
* size: 10
* style: Negreta
* included characters:  !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~ª²¯ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿº³¿
* antialiasing: <value not defined>
* type: proportional
* encoding: WINDOWS-1251
* unicode bom: yes
*
* preset name: Monochrome
* data block size: 8 bit(s), uint8_t
* conversion type: Monochrome, Diffuse Dither 128
* bits per pixel: 1
*
* preprocess:
*  rotate: <value not defined>
*  flip horizontal: <value not defined>
*  flip vertical: <value not defined>
*  inverse: yes
*******************************************************************************/

/*
 typedef struct {
     long int code;
     const tImage *image;
     } tChar;
 typedef struct {
     int length;
     const tChar *chars;
     } tFont;
*/

#include <stdint.h>
#include "font.h"


static const uint8_t image_data_Arial7_0x20[3] = {
    0x00, 0x00, 0x00
};
static const tImage Arial7_0x20 = { image_data_Arial7_0x20, 3, 7};//' '
static const uint8_t image_data_Arial7_0x21[2] = {
    0xaa, 0x88
};
static const tImage Arial7_0x21 = { image_data_Arial7_0x21, 2, 7};//'!'
static const uint8_t image_data_Arial7_0x22[3] = {
    0xb6, 0x80, 0x00
};
static const tImage Arial7_0x22 = { image_data_Arial7_0x22, 3, 7};//'"'
static const uint8_t image_data_Arial7_0x23[5] = {
    0x52, 0xbe, 0xaf, 0xa9, 0x40
};
static const tImage Arial7_0x23 = { image_data_Arial7_0x23, 5, 7};//'#'
static const uint8_t image_data_Arial7_0x24[6] = {
	0x04, 0x30, 0xb6, 0x70, 0x8f, 0xc0
    /* 0x75, 0x68, 0xe2, 0xd5, 0xc0 */
};
static const tImage Arial7_0x24 = { image_data_Arial7_0x24, 6, 7};//'$'
static const uint8_t image_data_Arial7_0x25[6] = {
    0xe6, 0xab, 0x3f, 0x35, 0x59, 0xc0
};
static const tImage Arial7_0x25 = { image_data_Arial7_0x25, 6, 7};//'%'
static const uint8_t image_data_Arial7_0x26[5] = {
    0x72, 0x94, 0xc9, 0xc9, 0xa0
};
static const tImage Arial7_0x26 = { image_data_Arial7_0x26, 5, 7};//'&'
static const uint8_t image_data_Arial7_0x27[2] = {
    0xa8, 0x00
};
static const tImage Arial7_0x27 = { image_data_Arial7_0x27, 2, 7};//'''
static const uint8_t image_data_Arial7_0x28[2] = {
    0x6a, 0xa4
};
static const tImage Arial7_0x28 = { image_data_Arial7_0x28, 2, 7};//'('
static const uint8_t image_data_Arial7_0x29[2] = {
    0x95, 0x58
};
static const tImage Arial7_0x29 = { image_data_Arial7_0x29, 2, 7};//')'
static const uint8_t image_data_Arial7_0x2a[3] = {
    0x5d, 0x50, 0x00
};
static const tImage Arial7_0x2a = { image_data_Arial7_0x2a, 3, 7};//'*'
static const uint8_t image_data_Arial7_0x2b[5] = {
    0x01, 0x09, 0xf2, 0x10, 0x00
};
static const tImage Arial7_0x2b = { image_data_Arial7_0x2b, 5, 7};//'+'
static const uint8_t image_data_Arial7_0x2c[2] = {
    0x00, 0x04
};
static const tImage Arial7_0x2c = { image_data_Arial7_0x2c, 2, 7};//','
static const uint8_t image_data_Arial7_0x2d[3] = {
    0x00, 0x0e, 0x00
};
static const tImage Arial7_0x2d = { image_data_Arial7_0x2d, 3, 7};//'-'
static const uint8_t image_data_Arial7_0x2e[2] = {
    0x00, 0x04
};
static const tImage Arial7_0x2e = { image_data_Arial7_0x2e, 2, 7};//'.'
static const uint8_t image_data_Arial7_0x2f[3] = {
    0x25, 0x25, 0x20
};
static const tImage Arial7_0x2f = { image_data_Arial7_0x2f, 3, 7};//'/'
static const uint8_t image_data_Arial7_0x30[5] = {
    0x74, 0x63, 0x18, 0xc5, 0xc0
};
static const tImage Arial7_0x30 = { image_data_Arial7_0x30, 5, 7};//'0'
static const uint8_t image_data_Arial7_0x31[3] = {
    0x2e, 0x92, 0x48
};
static const tImage Arial7_0x31 = { image_data_Arial7_0x31, 3, 7};//'1'
static const uint8_t image_data_Arial7_0x32[5] = {
    0x74, 0x42, 0x22, 0x23, 0xe0
};
static const tImage Arial7_0x32 = { image_data_Arial7_0x32, 5, 7};//'2'
static const uint8_t image_data_Arial7_0x33[5] = {
    0x74, 0x42, 0x60, 0xc5, 0xc0
};
static const tImage Arial7_0x33 = { image_data_Arial7_0x33, 5, 7};//'3'
static const uint8_t image_data_Arial7_0x34[5] = {
    0x11, 0x94, 0xa9, 0x7c, 0x40
};
static const tImage Arial7_0x34 = { image_data_Arial7_0x34, 5, 7};//'4'
static const uint8_t image_data_Arial7_0x35[5] = {
    0xfc, 0x3d, 0x10, 0xc5, 0xc0
};
static const tImage Arial7_0x35 = { image_data_Arial7_0x35, 5, 7};//'5'
static const uint8_t image_data_Arial7_0x36[5] = {
    0x74, 0x61, 0xe8, 0xc5, 0xc0
};
static const tImage Arial7_0x36 = { image_data_Arial7_0x36, 5, 7};//'6'
static const uint8_t image_data_Arial7_0x37[5] = {
    0xf8, 0x44, 0x22, 0x10, 0x80
};
static const tImage Arial7_0x37 = { image_data_Arial7_0x37, 5, 7};//'7'
static const uint8_t image_data_Arial7_0x38[5] = {
    0x74, 0x62, 0xe8, 0xc5, 0xc0
};
static const tImage Arial7_0x38 = { image_data_Arial7_0x38, 5, 7};//'8'
static const uint8_t image_data_Arial7_0x39[5] = {
    0x74, 0x62, 0xf0, 0xc5, 0xc0
};
static const tImage Arial7_0x39 = { image_data_Arial7_0x39, 5, 7};//'9'
static const uint8_t image_data_Arial7_0x3a[2] = {
    0x04, 0x04
};
static const tImage Arial7_0x3a = { image_data_Arial7_0x3a, 2, 7};//':'
static const uint8_t image_data_Arial7_0x3b[2] = {
    0x04, 0x14
};
static const tImage Arial7_0x3b = { image_data_Arial7_0x3b, 2, 7};//';'
static const uint8_t image_data_Arial7_0x3c[3] = {
    0x05, 0x44, 0x40
};
static const tImage Arial7_0x3c = { image_data_Arial7_0x3c, 3, 7};//'<'
static const uint8_t image_data_Arial7_0x3d[5] = {
    0x00, 0x3e, 0x0f, 0x80, 0x00
};
static const tImage Arial7_0x3d = { image_data_Arial7_0x3d, 5, 7};//'='
static const uint8_t image_data_Arial7_0x3e[3] = {
    0x11, 0x15, 0x00
};
static const tImage Arial7_0x3e = { image_data_Arial7_0x3e, 3, 7};//'>'
static const uint8_t image_data_Arial7_0x3f[5] = {
    0x74, 0x42, 0x22, 0x00, 0x80
};
static const tImage Arial7_0x3f = { image_data_Arial7_0x3f, 5, 7};//'?'
static const uint8_t image_data_Arial7_0x40[7] = {
    0x7e, 0x81, 0x99, 0xa5, 0xa5, 0x9e, 0xc0
};
static const tImage Arial7_0x40 = { image_data_Arial7_0x40, 8, 7};//'(a)'
static const uint8_t image_data_Arial7_0x41[5] = {
    0x19, 0x53, 0x1f, 0xc6, 0x20
};
static const tImage Arial7_0x41 = { image_data_Arial7_0x41, 5, 7};//'A'
static const uint8_t image_data_Arial7_0x42[5] = {
    0xf4, 0x63, 0xe8, 0xc7, 0xc0
};
static const tImage Arial7_0x42 = { image_data_Arial7_0x42, 5, 7};//'B'
static const uint8_t image_data_Arial7_0x43[5] = {
    0x74, 0x61, 0x08, 0x45, 0xc0
};
static const tImage Arial7_0x43 = { image_data_Arial7_0x43, 5, 7};//'C'
static const uint8_t image_data_Arial7_0x44[5] = {
    0xf4, 0x63, 0x18, 0xc7, 0xc0
};
static const tImage Arial7_0x44 = { image_data_Arial7_0x44, 5, 7};//'D'
static const uint8_t image_data_Arial7_0x45[5] = {
    0xfc, 0x21, 0xf8, 0x43, 0xe0
};
static const tImage Arial7_0x45 = { image_data_Arial7_0x45, 5, 7};//'E'
static const uint8_t image_data_Arial7_0x46[4] = {
    0xf8, 0x8f, 0x88, 0x80
};
static const tImage Arial7_0x46 = { image_data_Arial7_0x46, 4, 7};//'F'
static const uint8_t image_data_Arial7_0x47[5] = {
    0x74, 0x61, 0x68, 0xc5, 0xc0
};
static const tImage Arial7_0x47 = { image_data_Arial7_0x47, 5, 7};//'G'
static const uint8_t image_data_Arial7_0x48[5] = {
    0x8c, 0x63, 0xf8, 0xc6, 0x20
};
static const tImage Arial7_0x48 = { image_data_Arial7_0x48, 5, 7};//'H'
static const uint8_t image_data_Arial7_0x49[2] = {
    0xaa, 0xa8
};
static const tImage Arial7_0x49 = { image_data_Arial7_0x49, 2, 7};//'I'
static const uint8_t image_data_Arial7_0x4a[4] = {
    0x11, 0x11, 0x19, 0x60
};
static const tImage Arial7_0x4a = { image_data_Arial7_0x4a, 4, 7};//'J'
static const uint8_t image_data_Arial7_0x4b[5] = {
    0x8c, 0xa9, 0x8a, 0x4a, 0x20
};
static const tImage Arial7_0x4b = { image_data_Arial7_0x4b, 5, 7};//'K'
static const uint8_t image_data_Arial7_0x4c[4] = {
    0x88, 0x88, 0x88, 0xf0
};
static const tImage Arial7_0x4c = { image_data_Arial7_0x4c, 4, 7};//'L'
static const uint8_t image_data_Arial7_0x4d[7] = {
    0xc7, 0x8e, 0xad, 0x5a, 0xb2, 0x64, 0x80
};
static const tImage Arial7_0x4d = { image_data_Arial7_0x4d, 7, 7};//'M'
static const uint8_t image_data_Arial7_0x4e[5] = {
    0x8e, 0x73, 0x59, 0xce, 0x20
};
static const tImage Arial7_0x4e = { image_data_Arial7_0x4e, 5, 7};//'N'
static const uint8_t image_data_Arial7_0x4f[5] = {
    0x74, 0x63, 0x18, 0xc5, 0xc0
};
static const tImage Arial7_0x4f = { image_data_Arial7_0x4f, 5, 7};//'O'
static const uint8_t image_data_Arial7_0x50[5] = {
    0xf4, 0x63, 0xe8, 0x42, 0x00
};
static const tImage Arial7_0x50 = { image_data_Arial7_0x50, 5, 7};//'P'
static const uint8_t image_data_Arial7_0x51[5] = {
    0x74, 0x63, 0x1a, 0xcd, 0xc0
};
static const tImage Arial7_0x51 = { image_data_Arial7_0x51, 5, 7};//'Q'
static const uint8_t image_data_Arial7_0x52[5] = {
    0xf4, 0x63, 0xea, 0x4a, 0x20
};
static const tImage Arial7_0x52 = { image_data_Arial7_0x52, 5, 7};//'R'
static const uint8_t image_data_Arial7_0x53[5] = {
    0x74, 0x60, 0xe0, 0xc5, 0xc0
};
static const tImage Arial7_0x53 = { image_data_Arial7_0x53, 5, 7};//'S'
static const uint8_t image_data_Arial7_0x54[5] = {
    0xf9, 0x08, 0x42, 0x10, 0x80
};
static const tImage Arial7_0x54 = { image_data_Arial7_0x54, 5, 7};//'T'
static const uint8_t image_data_Arial7_0x55[5] = {
    0x8c, 0x63, 0x18, 0xc5, 0xc0
};
static const tImage Arial7_0x55 = { image_data_Arial7_0x55, 5, 7};//'U'
static const uint8_t image_data_Arial7_0x56[5] = {
    0x8c, 0x62, 0xa5, 0x28, 0x80
};
static const tImage Arial7_0x56 = { image_data_Arial7_0x56, 5, 7};//'V'
static const uint8_t image_data_Arial7_0x57[5] = {
    0xad, 0x6b, 0x5a, 0xd5, 0x40
};
static const tImage Arial7_0x57 = { image_data_Arial7_0x57, 5, 7};//'W'
static const uint8_t image_data_Arial7_0x58[5] = {
    0x8c, 0x54, 0x45, 0x46, 0x20
};
static const tImage Arial7_0x58 = { image_data_Arial7_0x58, 5, 7};//'X'
static const uint8_t image_data_Arial7_0x59[5] = {
    0x8c, 0x54, 0x42, 0x10, 0x80
};
static const tImage Arial7_0x59 = { image_data_Arial7_0x59, 5, 7};//'Y'
static const uint8_t image_data_Arial7_0x5a[5] = {
    0xf8, 0x44, 0x44, 0x43, 0xe0
};
static const tImage Arial7_0x5a = { image_data_Arial7_0x5a, 5, 7};//'Z'
static const uint8_t image_data_Arial7_0x5b[2] = {
    0xea, 0xac
};
static const tImage Arial7_0x5b = { image_data_Arial7_0x5b, 2, 7};//'['
static const uint8_t image_data_Arial7_0x5c[3] = {
    0x91, 0x24, 0x48
};
static const tImage Arial7_0x5c = { image_data_Arial7_0x5c, 3, 7};//'\'
static const uint8_t image_data_Arial7_0x5d[2] = {
    0xd5, 0x5c
};
static const tImage Arial7_0x5d = { image_data_Arial7_0x5d, 2, 7};//']'
static const uint8_t image_data_Arial7_0x5e[5] = {
    0x01, 0x15, 0x10, 0x00, 0x00
};
static const tImage Arial7_0x5e = { image_data_Arial7_0x5e, 5, 7};//'^'
static const uint8_t image_data_Arial7_0x5f[5] = {
    0x00, 0x00, 0x00, 0x03, 0xe0
};
static const tImage Arial7_0x5f = { image_data_Arial7_0x5f, 5, 7};//'_'
static const uint8_t image_data_Arial7_0x60[2] = {
    0x90, 0x00
};
static const tImage Arial7_0x60 = { image_data_Arial7_0x60, 2, 7};//'`'
static const uint8_t image_data_Arial7_0x61[5] = {
    0x00, 0x3c, 0x17, 0xc5, 0xe0
};
static const tImage Arial7_0x61 = { image_data_Arial7_0x61, 5, 7};//'a'
static const uint8_t image_data_Arial7_0x62[5] = {
    0x84, 0x3d, 0x18, 0xc7, 0xc0
};
static const tImage Arial7_0x62 = { image_data_Arial7_0x62, 5, 7};//'b'
static const uint8_t image_data_Arial7_0x63[5] = {
    0x00, 0x1d, 0x18, 0x45, 0xc0
};
static const tImage Arial7_0x63 = { image_data_Arial7_0x63, 5, 7};//'c'
static const uint8_t image_data_Arial7_0x64[5] = {
    0x08, 0x5f, 0x18, 0xc5, 0xe0
};
static const tImage Arial7_0x64 = { image_data_Arial7_0x64, 5, 7};//'d'
static const uint8_t image_data_Arial7_0x65[5] = {
    0x00, 0x1d, 0x1f, 0xc1, 0xe0
};
static const tImage Arial7_0x65 = { image_data_Arial7_0x65, 5, 7};//'e'
static const uint8_t image_data_Arial7_0x66[2] = {
    0xee, 0xa8
};
static const tImage Arial7_0x66 = { image_data_Arial7_0x66, 2, 7};//'f'
static const uint8_t image_data_Arial7_0x67[5] = {
    0x00, 0x1f, 0x17, 0x85, 0xe0
};
static const tImage Arial7_0x67 = { image_data_Arial7_0x67, 5, 7};//'g'
static const uint8_t image_data_Arial7_0x68[5] = {
    0x84, 0x3d, 0x18, 0xc6, 0x20
};
static const tImage Arial7_0x68 = { image_data_Arial7_0x68, 5, 7};//'h'
static const uint8_t image_data_Arial7_0x69[2] = {
    0x8a, 0xa8
};
static const tImage Arial7_0x69 = { image_data_Arial7_0x69, 2, 7};//'i'
static const uint8_t image_data_Arial7_0x6a[2] = {
    0x45, 0x5c
};
static const tImage Arial7_0x6a = { image_data_Arial7_0x6a, 2, 7};//'j'
static const uint8_t image_data_Arial7_0x6b[4] = {
    0x88, 0x9a, 0xca, 0x90
};
static const tImage Arial7_0x6b = { image_data_Arial7_0x6b, 4, 7};//'k'
static const uint8_t image_data_Arial7_0x6c[2] = {
    0xaa, 0xa8
};
static const tImage Arial7_0x6c = { image_data_Arial7_0x6c, 2, 7};//'l'
static const uint8_t image_data_Arial7_0x6d[5] = {
    0x00, 0x1d, 0x5a, 0xd6, 0xa0
};
static const tImage Arial7_0x6d = { image_data_Arial7_0x6d, 5, 7};//'m'
static const uint8_t image_data_Arial7_0x6e[5] = {
    0x00, 0x3d, 0x18, 0xc6, 0x20
};
static const tImage Arial7_0x6e = { image_data_Arial7_0x6e, 5, 7};//'n'
static const uint8_t image_data_Arial7_0x6f[5] = {
    0x00, 0x1d, 0x18, 0xc5, 0xc0
};
static const tImage Arial7_0x6f = { image_data_Arial7_0x6f, 5, 7};//'o'
static const uint8_t image_data_Arial7_0x70[5] = {
    0x00, 0x3d, 0x1f, 0x42, 0x00
};
static const tImage Arial7_0x70 = { image_data_Arial7_0x70, 5, 7};//'p'
static const uint8_t image_data_Arial7_0x71[5] = {
    0x00, 0x1f, 0x17, 0x84, 0x20
};
static const tImage Arial7_0x71 = { image_data_Arial7_0x71, 5, 7};//'q'
static const uint8_t image_data_Arial7_0x72[4] = {
    0x00, 0xf8, 0x88, 0x80
};
static const tImage Arial7_0x72 = { image_data_Arial7_0x72, 4, 7};//'r'
static const uint8_t image_data_Arial7_0x73[5] = {
    0x00, 0x1f, 0x07, 0x07, 0xc0
};
static const tImage Arial7_0x73 = { image_data_Arial7_0x73, 5, 7};//'s'
static const uint8_t image_data_Arial7_0x74[3] = {
    0x4b, 0xa4, 0x98
};
static const tImage Arial7_0x74 = { image_data_Arial7_0x74, 3, 7};//'t'
static const uint8_t image_data_Arial7_0x75[5] = {
    0x00, 0x23, 0x18, 0xc5, 0xe0
};
static const tImage Arial7_0x75 = { image_data_Arial7_0x75, 5, 7};//'u'
static const uint8_t image_data_Arial7_0x76[5] = {
    0x00, 0x23, 0x18, 0xa8, 0x80
};
static const tImage Arial7_0x76 = { image_data_Arial7_0x76, 5, 7};//'v'
static const uint8_t image_data_Arial7_0x77[5] = {
    0x00, 0x2b, 0x5a, 0xd5, 0x40
};
static const tImage Arial7_0x77 = { image_data_Arial7_0x77, 5, 7};//'w'
static const uint8_t image_data_Arial7_0x78[5] = {
    0x00, 0x22, 0xa2, 0x2a, 0x20
};
static const tImage Arial7_0x78 = { image_data_Arial7_0x78, 5, 7};//'x'
static const uint8_t image_data_Arial7_0x79[5] = {
    0x00, 0x23, 0x17, 0x85, 0xc0
};
static const tImage Arial7_0x79 = { image_data_Arial7_0x79, 5, 7};//'y'
static const uint8_t image_data_Arial7_0x7a[5] = {
    0x00, 0x3e, 0x22, 0x23, 0xe0
};
static const tImage Arial7_0x7a = { image_data_Arial7_0x7a, 5, 7};//'z'
static const uint8_t image_data_Arial7_0x7b[3] = {
    0x69, 0x44, 0x98
};
static const tImage Arial7_0x7b = { image_data_Arial7_0x7b, 3, 7};//'{'
static const uint8_t image_data_Arial7_0x7c[2] = {
    0xaa, 0xa8
};
static const tImage Arial7_0x7c = { image_data_Arial7_0x7c, 2, 7};//'|'
static const uint8_t image_data_Arial7_0x7d[3] = {
    0xc9, 0x14, 0xb0
};
static const tImage Arial7_0x7d = { image_data_Arial7_0x7d, 3, 7};//'}'
static const uint8_t image_data_Arial7_0x7e[4] = {
    0x00, 0x5a, 0x00, 0x00
};
static const tImage Arial7_0x7e = { image_data_Arial7_0x7e, 4, 7};//'~'
static const uint8_t image_data_Arial7_0xaa[5] = {
    0x74, 0x61, 0xc8, 0x45, 0xc0
};
static const tImage Arial7_0xaa = { image_data_Arial7_0xaa, 5, 7};//'ª'
static const uint8_t image_data_Arial7_0xb2[2] = {
    0xaa, 0xa8
};
static const tImage Arial7_0xb2 = { image_data_Arial7_0xb2, 2, 7};//'²'
static const uint8_t image_data_Arial7_0xaf[3] = {
    0xa9, 0x24, 0x90
};
static const tImage Arial7_0xaf = { image_data_Arial7_0xaf, 3, 7};//'¯'
static const uint8_t image_data_Arial7_0xc0[5] = {
    0x3a, 0x63, 0x1f, 0xc6, 0x20
};
static const tImage Arial7_0xc0 = { image_data_Arial7_0xc0, 5, 7};//'À'
static const uint8_t image_data_Arial7_0xc1[5] = {
    0xf4, 0x21, 0xe8, 0xc7, 0xc0
};
static const tImage Arial7_0xc1 = { image_data_Arial7_0xc1, 5, 7};//'Á'
static const uint8_t image_data_Arial7_0xc2[5] = {
    0xf4, 0x63, 0xe8, 0xc7, 0xc0
};
static const tImage Arial7_0xc2 = { image_data_Arial7_0xc2, 5, 7};//'Â'
static const uint8_t image_data_Arial7_0xc3[4] = {
    0xf8, 0x88, 0x88, 0x80
};
static const tImage Arial7_0xc3 = { image_data_Arial7_0xc3, 4, 7};//'Ã'
static const uint8_t image_data_Arial7_0xc4[5] = {
    0x72, 0x94, 0xa5, 0x7e, 0x20
};
static const tImage Arial7_0xc4 = { image_data_Arial7_0xc4, 5, 7};//'Ä'
static const uint8_t image_data_Arial7_0xc5[5] = {
    0xfc, 0x21, 0xf8, 0x43, 0xe0
};
static const tImage Arial7_0xc5 = { image_data_Arial7_0xc5, 5, 7};//'Å'
static const uint8_t image_data_Arial7_0xc6[5] = {
    0xad, 0x6a, 0xea, 0xd6, 0xa0
};
static const tImage Arial7_0xc6 = { image_data_Arial7_0xc6, 5, 7};//'Æ'
static const uint8_t image_data_Arial7_0xc7[4] = {
    0x69, 0x12, 0x19, 0x60
};
static const tImage Arial7_0xc7 = { image_data_Arial7_0xc7, 4, 7};//'Ç'
static const uint8_t image_data_Arial7_0xc8[5] = {
    0x8c, 0xe7, 0x5c, 0xe6, 0x20
};
static const tImage Arial7_0xc8 = { image_data_Arial7_0xc8, 5, 7};//'È'
static const uint8_t image_data_Arial7_0xc9[5] = {
    0xac, 0x67, 0x5c, 0xc6, 0x20
};
static const tImage Arial7_0xc9 = { image_data_Arial7_0xc9, 5, 7};//'É'
static const uint8_t image_data_Arial7_0xca[5] = {
    0x8c, 0xa9, 0x8a, 0x4a, 0x20
};
static const tImage Arial7_0xca = { image_data_Arial7_0xca, 5, 7};//'Ê'
static const uint8_t image_data_Arial7_0xcb[5] = {
    0x3a, 0x63, 0x18, 0xc6, 0x20
};
static const tImage Arial7_0xcb = { image_data_Arial7_0xcb, 5, 7};//'Ë'
static const uint8_t image_data_Arial7_0xcc[5] = {
    0x8e, 0xf7, 0x5a, 0xd6, 0xa0
};
static const tImage Arial7_0xcc = { image_data_Arial7_0xcc, 5, 7};//'Ì'
static const uint8_t image_data_Arial7_0xcd[5] = {
    0x8c, 0x63, 0xf8, 0xc6, 0x20
};
static const tImage Arial7_0xcd = { image_data_Arial7_0xcd, 5, 7};//'Í'
static const uint8_t image_data_Arial7_0xce[5] = {
    0x74, 0x63, 0x18, 0xc5, 0xc0
};
static const tImage Arial7_0xce = { image_data_Arial7_0xce, 5, 7};//'Î'
static const uint8_t image_data_Arial7_0xcf[5] = {
    0xfc, 0x63, 0x18, 0xc6, 0x20
};
static const tImage Arial7_0xcf = { image_data_Arial7_0xcf, 5, 7};//'Ï'
static const uint8_t image_data_Arial7_0xd0[5] = {
    0xf4, 0x63, 0xe8, 0x42, 0x00
};
static const tImage Arial7_0xd0 = { image_data_Arial7_0xd0, 5, 7};//'Ð'
static const uint8_t image_data_Arial7_0xd1[5] = {
    0x74, 0x61, 0x08, 0x45, 0xc0
};
static const tImage Arial7_0xd1 = { image_data_Arial7_0xd1, 5, 7};//'Ñ'
static const uint8_t image_data_Arial7_0xd2[5] = {
    0xf9, 0x08, 0x42, 0x10, 0x80
};
static const tImage Arial7_0xd2 = { image_data_Arial7_0xd2, 5, 7};//'Ò'
static const uint8_t image_data_Arial7_0xd3[5] = {
    0x8c, 0x62, 0xf0, 0x85, 0xc0
};
static const tImage Arial7_0xd3 = { image_data_Arial7_0xd3, 5, 7};//'Ó'
static const uint8_t image_data_Arial7_0xd4[5] = {
    0x75, 0x6b, 0x5a, 0xb8, 0x80
};
static const tImage Arial7_0xd4 = { image_data_Arial7_0xd4, 5, 7};//'Ô'
static const uint8_t image_data_Arial7_0xd5[5] = {
    0x8a, 0x94, 0x45, 0x2a, 0x20
};
static const tImage Arial7_0xd5 = { image_data_Arial7_0xd5, 5, 7};//'Õ'
static const uint8_t image_data_Arial7_0xd6[5] = {
    0x8c, 0x63, 0x18, 0xfc, 0x20
};
static const tImage Arial7_0xd6 = { image_data_Arial7_0xd6, 5, 7};//'Ö'
static const uint8_t image_data_Arial7_0xd7[5] = {
    0x8c, 0x63, 0x17, 0x84, 0x20
};
static const tImage Arial7_0xd7 = { image_data_Arial7_0xd7, 5, 7};//'×'
static const uint8_t image_data_Arial7_0xd8[5] = {
    0xad, 0x6b, 0x5a, 0xd7, 0xe0
};
static const tImage Arial7_0xd8 = { image_data_Arial7_0xd8, 5, 7};//'Ø'
static const uint8_t image_data_Arial7_0xd9[5] = {
    0xad, 0x6b, 0x5a, 0xfc, 0x20
};
static const tImage Arial7_0xd9 = { image_data_Arial7_0xd9, 5, 7};//'Ù'
static const uint8_t image_data_Arial7_0xda[5] = {
    0xc2, 0x10, 0xe4, 0xa5, 0xc0
};
static const tImage Arial7_0xda = { image_data_Arial7_0xda, 5, 7};//'Ú'
static const uint8_t image_data_Arial7_0xdb[5] = {
    0x8c, 0x63, 0x9a, 0xd7, 0x20
};
static const tImage Arial7_0xdb = { image_data_Arial7_0xdb, 5, 7};//'Û'
static const uint8_t image_data_Arial7_0xdc[5] = {
    0x84, 0x21, 0xe8, 0xc7, 0xc0
};
static const tImage Arial7_0xdc = { image_data_Arial7_0xdc, 5, 7};//'Ü'
static const uint8_t image_data_Arial7_0xdd[5] = {
    0x74, 0x42, 0x70, 0xc5, 0xc0
};
static const tImage Arial7_0xdd = { image_data_Arial7_0xdd, 5, 7};//'Ý'
static const uint8_t image_data_Arial7_0xde[5] = {
    0x95, 0x6b, 0xda, 0xd6, 0x40
};
static const tImage Arial7_0xde = { image_data_Arial7_0xde, 5, 7};//'Þ'
static const uint8_t image_data_Arial7_0xdf[5] = {
    0x7c, 0x62, 0xf2, 0xa6, 0x20
};
static const tImage Arial7_0xdf = { image_data_Arial7_0xdf, 5, 7};//'ß'
static const uint8_t image_data_Arial7_0xe0[5] = {
    0x00, 0x3c, 0x17, 0xc5, 0xe0
};
static const tImage Arial7_0xe0 = { image_data_Arial7_0xe0, 5, 7};//'à'
static const uint8_t image_data_Arial7_0xe1[5] = {
    0x7c, 0x3d, 0x18, 0xc5, 0xc0
};
static const tImage Arial7_0xe1 = { image_data_Arial7_0xe1, 5, 7};//'á'
static const uint8_t image_data_Arial7_0xe2[5] = {
    0x00, 0x3d, 0x1f, 0x47, 0xc0
};
static const tImage Arial7_0xe2 = { image_data_Arial7_0xe2, 5, 7};//'â'
static const uint8_t image_data_Arial7_0xe3[4] = {
    0x00, 0xf8, 0x88, 0x80
};
static const tImage Arial7_0xe3 = { image_data_Arial7_0xe3, 4, 7};//'ã'
static const uint8_t image_data_Arial7_0xe4[5] = {
    0x00, 0x0e, 0x52, 0xa7, 0xe0
};
static const tImage Arial7_0xe4 = { image_data_Arial7_0xe4, 5, 7};//'ä'
static const uint8_t image_data_Arial7_0xe5[5] = {
    0x00, 0x1d, 0x1f, 0xc1, 0xc0
};
static const tImage Arial7_0xe5 = { image_data_Arial7_0xe5, 5, 7};//'å'
static const uint8_t image_data_Arial7_0xe6[5] = {
    0x00, 0x2b, 0x57, 0x56, 0xa0
};
static const tImage Arial7_0xe6 = { image_data_Arial7_0xe6, 5, 7};//'æ'
static const uint8_t image_data_Arial7_0xe7[4] = {
    0x00, 0x69, 0x29, 0x60
};
static const tImage Arial7_0xe7 = { image_data_Arial7_0xe7, 4, 7};//'ç'
static const uint8_t image_data_Arial7_0xe8[5] = {
    0x00, 0x23, 0x3a, 0xe6, 0x20
};
static const tImage Arial7_0xe8 = { image_data_Arial7_0xe8, 5, 7};//'è'
static const uint8_t image_data_Arial7_0xe9[5] = {
    0x70, 0x23, 0x3a, 0xe6, 0x20
};
static const tImage Arial7_0xe9 = { image_data_Arial7_0xe9, 5, 7};//'é'
static const uint8_t image_data_Arial7_0xea[4] = {
    0x00, 0x9a, 0xca, 0x90
};
static const tImage Arial7_0xea = { image_data_Arial7_0xea, 4, 7};//'ê'
static const uint8_t image_data_Arial7_0xeb[5] = {
    0x00, 0x1e, 0x94, 0xa6, 0x20
};
static const tImage Arial7_0xeb = { image_data_Arial7_0xeb, 5, 7};//'ë'
static const uint8_t image_data_Arial7_0xec[5] = {
    0x00, 0x23, 0xbd, 0xd6, 0xa0
};
static const tImage Arial7_0xec = { image_data_Arial7_0xec, 5, 7};//'ì'
static const uint8_t image_data_Arial7_0xed[5] = {
    0x00, 0x23, 0x1f, 0xc6, 0x20
};
static const tImage Arial7_0xed = { image_data_Arial7_0xed, 5, 7};//'í'
static const uint8_t image_data_Arial7_0xee[5] = {
    0x00, 0x1d, 0x18, 0xc5, 0xc0
};
static const tImage Arial7_0xee = { image_data_Arial7_0xee, 5, 7};//'î'
static const uint8_t image_data_Arial7_0xef[5] = {
    0x00, 0x3f, 0x18, 0xc6, 0x20
};
static const tImage Arial7_0xef = { image_data_Arial7_0xef, 5, 7};//'ï'
static const uint8_t image_data_Arial7_0xf0[5] = {
    0x00, 0x3d, 0x1f, 0x42, 0x00
};
static const tImage Arial7_0xf0 = { image_data_Arial7_0xf0, 5, 7};//'ð'
static const uint8_t image_data_Arial7_0xf1[5] = {
    0x00, 0x1d, 0x18, 0x45, 0xc0
};
static const tImage Arial7_0xf1 = { image_data_Arial7_0xf1, 5, 7};//'ñ'
static const uint8_t image_data_Arial7_0xf2[5] = {
    0x00, 0x3e, 0x42, 0x10, 0x80
};
static const tImage Arial7_0xf2 = { image_data_Arial7_0xf2, 5, 7};//'ò'
static const uint8_t image_data_Arial7_0xf3[5] = {
    0x00, 0x23, 0x17, 0x85, 0xc0
};
static const tImage Arial7_0xf3 = { image_data_Arial7_0xf3, 5, 7};//'ó'
static const uint8_t image_data_Arial7_0xf4[5] = {
    0x00, 0x1d, 0x5a, 0xb8, 0x80
};
static const tImage Arial7_0xf4 = { image_data_Arial7_0xf4, 5, 7};//'ô'
static const uint8_t image_data_Arial7_0xf5[5] = {
    0x00, 0x22, 0xa2, 0x2a, 0x20
};
static const tImage Arial7_0xf5 = { image_data_Arial7_0xf5, 5, 7};//'õ'
static const uint8_t image_data_Arial7_0xf6[5] = {
    0x00, 0x25, 0x29, 0x4b, 0xe0
};
static const tImage Arial7_0xf6 = { image_data_Arial7_0xf6, 5, 7};//'ö'
static const uint8_t image_data_Arial7_0xf7[5] = {
    0x00, 0x23, 0x17, 0x84, 0x20
};
static const tImage Arial7_0xf7 = { image_data_Arial7_0xf7, 5, 7};//'÷'
static const uint8_t image_data_Arial7_0xf8[5] = {
    0x00, 0x2b, 0x5a, 0xd7, 0xe0
};
static const tImage Arial7_0xf8 = { image_data_Arial7_0xf8, 5, 7};//'ø'
static const uint8_t image_data_Arial7_0xf9[5] = {
    0x00, 0x2b, 0x5a, 0xfc, 0x20
};
static const tImage Arial7_0xf9 = { image_data_Arial7_0xf9, 5, 7};//'ù'
static const uint8_t image_data_Arial7_0xfa[5] = {
    0x00, 0x30, 0x87, 0xa5, 0xe0
};
static const tImage Arial7_0xfa = { image_data_Arial7_0xfa, 5, 7};//'ú'
static const uint8_t image_data_Arial7_0xfb[5] = {
    0x00, 0x23, 0x1c, 0xd7, 0x20
};
static const tImage Arial7_0xfb = { image_data_Arial7_0xfb, 5, 7};//'û'
static const uint8_t image_data_Arial7_0xfc[5] = {
    0x00, 0x21, 0x0f, 0x47, 0xc0
};
static const tImage Arial7_0xfc = { image_data_Arial7_0xfc, 5, 7};//'ü'
static const uint8_t image_data_Arial7_0xfd[5] = {
    0x00, 0x1d, 0x13, 0xc5, 0xc0
};
static const tImage Arial7_0xfd = { image_data_Arial7_0xfd, 5, 7};//'ý'
static const uint8_t image_data_Arial7_0xfe[5] = {
    0x00, 0x25, 0x5e, 0xd6, 0x40
};
static const tImage Arial7_0xfe = { image_data_Arial7_0xfe, 5, 7};//'þ'
static const uint8_t image_data_Arial7_0xff[5] = {
    0x00, 0x1f, 0x17, 0xa6, 0x20
};
static const tImage Arial7_0xff = { image_data_Arial7_0xff, 5, 7};//'ÿ'
static const uint8_t image_data_Arial7_0xba[5] = {
    0x00, 0x1d, 0x1e, 0x45, 0xc0
};
static const tImage Arial7_0xba = { image_data_Arial7_0xba, 5, 7};//'º'
static const uint8_t image_data_Arial7_0xb3[2] = {
    0x8a, 0xa8
};
static const tImage Arial7_0xb3 = { image_data_Arial7_0xb3, 2, 7};//'³'
static const uint8_t image_data_Arial7_0xbf[3] = {
    0xa1, 0x24, 0x90
};
static const tImage Arial7_0xbf = { image_data_Arial7_0xbf, 3, 7};//'¿'

static const tChar Arial7_array[] = {

// character: ' '
  {0x20, &Arial7_0x20},
// character: '!'
  {0x21, &Arial7_0x21},
// character: '"'
  {0x22, &Arial7_0x22},
// character: '#'
  {0x23, &Arial7_0x23},
// character: '$'
  {0x24, &Arial7_0x24},
// character: '%'
  {0x25, &Arial7_0x25},
// character: '&'
  {0x26, &Arial7_0x26},
// character: '''
  {0x27, &Arial7_0x27},
// character: '('
  {0x28, &Arial7_0x28},
// character: ')'
  {0x29, &Arial7_0x29},
// character: '*'
  {0x2a, &Arial7_0x2a},
// character: '+'
  {0x2b, &Arial7_0x2b},
// character: ','
  {0x2c, &Arial7_0x2c},
// character: '-'
  {0x2d, &Arial7_0x2d},
// character: '.'
  {0x2e, &Arial7_0x2e},
// character: '/'
  {0x2f, &Arial7_0x2f},
// character: '0'
  {0x30, &Arial7_0x30},
// character: '1'
  {0x31, &Arial7_0x31},
// character: '2'
  {0x32, &Arial7_0x32},
// character: '3'
  {0x33, &Arial7_0x33},
// character: '4'
  {0x34, &Arial7_0x34},
// character: '5'
  {0x35, &Arial7_0x35},
// character: '6'
  {0x36, &Arial7_0x36},
// character: '7'
  {0x37, &Arial7_0x37},
// character: '8'
  {0x38, &Arial7_0x38},
// character: '9'
  {0x39, &Arial7_0x39},
// character: ':'
  {0x3a, &Arial7_0x3a},
// character: ';'
  {0x3b, &Arial7_0x3b},
// character: '<'
  {0x3c, &Arial7_0x3c},
// character: '='
  {0x3d, &Arial7_0x3d},
// character: '>'
  {0x3e, &Arial7_0x3e},
// character: '?'
  {0x3f, &Arial7_0x3f},
// character: '(a)'
  {0x40, &Arial7_0x40},
// character: 'A'
  {0x41, &Arial7_0x41},
// character: 'B'
  {0x42, &Arial7_0x42},
// character: 'C'
  {0x43, &Arial7_0x43},
// character: 'D'
  {0x44, &Arial7_0x44},
// character: 'E'
  {0x45, &Arial7_0x45},
// character: 'F'
  {0x46, &Arial7_0x46},
// character: 'G'
  {0x47, &Arial7_0x47},
// character: 'H'
  {0x48, &Arial7_0x48},
// character: 'I'
  {0x49, &Arial7_0x49},
// character: 'J'
  {0x4a, &Arial7_0x4a},
// character: 'K'
  {0x4b, &Arial7_0x4b},
// character: 'L'
  {0x4c, &Arial7_0x4c},
// character: 'M'
  {0x4d, &Arial7_0x4d},
// character: 'N'
  {0x4e, &Arial7_0x4e},
// character: 'O'
  {0x4f, &Arial7_0x4f},
// character: 'P'
  {0x50, &Arial7_0x50},
// character: 'Q'
  {0x51, &Arial7_0x51},
// character: 'R'
  {0x52, &Arial7_0x52},
// character: 'S'
  {0x53, &Arial7_0x53},
// character: 'T'
  {0x54, &Arial7_0x54},
// character: 'U'
  {0x55, &Arial7_0x55},
// character: 'V'
  {0x56, &Arial7_0x56},
// character: 'W'
  {0x57, &Arial7_0x57},
// character: 'X'
  {0x58, &Arial7_0x58},
// character: 'Y'
  {0x59, &Arial7_0x59},
// character: 'Z'
  {0x5a, &Arial7_0x5a},
// character: '['
  {0x5b, &Arial7_0x5b},
// character: '\'
  {0x5c, &Arial7_0x5c},
// character: ']'
  {0x5d, &Arial7_0x5d},
// character: '^'
  {0x5e, &Arial7_0x5e},
// character: '_'
  {0x5f, &Arial7_0x5f},
// character: '`'
  {0x60, &Arial7_0x60},
// character: 'a'
  {0x61, &Arial7_0x61},
// character: 'b'
  {0x62, &Arial7_0x62},
// character: 'c'
  {0x63, &Arial7_0x63},
// character: 'd'
  {0x64, &Arial7_0x64},
// character: 'e'
  {0x65, &Arial7_0x65},
// character: 'f'
  {0x66, &Arial7_0x66},
// character: 'g'
  {0x67, &Arial7_0x67},
// character: 'h'
  {0x68, &Arial7_0x68},
// character: 'i'
  {0x69, &Arial7_0x69},
// character: 'j'
  {0x6a, &Arial7_0x6a},
// character: 'k'
  {0x6b, &Arial7_0x6b},
// character: 'l'
  {0x6c, &Arial7_0x6c},
// character: 'm'
  {0x6d, &Arial7_0x6d},
// character: 'n'
  {0x6e, &Arial7_0x6e},
// character: 'o'
  {0x6f, &Arial7_0x6f},
// character: 'p'
  {0x70, &Arial7_0x70},
// character: 'q'
  {0x71, &Arial7_0x71},
// character: 'r'
  {0x72, &Arial7_0x72},
// character: 's'
  {0x73, &Arial7_0x73},
// character: 't'
  {0x74, &Arial7_0x74},
// character: 'u'
  {0x75, &Arial7_0x75},
// character: 'v'
  {0x76, &Arial7_0x76},
// character: 'w'
  {0x77, &Arial7_0x77},
// character: 'x'
  {0x78, &Arial7_0x78},
// character: 'y'
  {0x79, &Arial7_0x79},
// character: 'z'
  {0x7a, &Arial7_0x7a},
// character: '{'
  {0x7b, &Arial7_0x7b},
// character: '|'
  {0x7c, &Arial7_0x7c},
// character: '}'
  {0x7d, &Arial7_0x7d},
// character: '~'
  {0x7e, &Arial7_0x7e},
// character: 'À'
  {0xc0, &Arial7_0xc0},
// character: 'Á'
  {0xc1, &Arial7_0xc1},
// character: 'Â'
  {0xc2, &Arial7_0xc2},
// character: 'Ã'
  {0xc3, &Arial7_0xc3},
// character: 'Ä'
  {0xc4, &Arial7_0xc4},
// character: 'Å'
  {0xc5, &Arial7_0xc5},
// character: 'Æ'
  {0xc6, &Arial7_0xc6},
// character: 'Ç'
  {0xc7, &Arial7_0xc7},
// character: 'È'
  {0xc8, &Arial7_0xc8},
// character: 'É'
  {0xc9, &Arial7_0xc9},
// character: 'Ê'
  {0xca, &Arial7_0xca},
// character: 'Ë'
  {0xcb, &Arial7_0xcb},
// character: 'Ì'
  {0xcc, &Arial7_0xcc},
// character: 'Í'
  {0xcd, &Arial7_0xcd},
// character: 'Î'
  {0xce, &Arial7_0xce},
// character: 'Ï'
  {0xcf, &Arial7_0xcf},
// character: 'Ð'
  {0xd0, &Arial7_0xd0},
// character: 'Ñ'
  {0xd1, &Arial7_0xd1},
// character: 'Ò'
  {0xd2, &Arial7_0xd2},
// character: 'Ó'
  {0xd3, &Arial7_0xd3},
// character: 'Ô'
  {0xd4, &Arial7_0xd4},
// character: 'Õ'
  {0xd5, &Arial7_0xd5},
// character: 'Ö'
  {0xd6, &Arial7_0xd6},
// character: '×'
  {0xd7, &Arial7_0xd7},
// character: 'Ø'
  {0xd8, &Arial7_0xd8},
// character: 'Ù'
  {0xd9, &Arial7_0xd9},
// character: 'Ú'
  {0xda, &Arial7_0xda},
// character: 'Û'
  {0xdb, &Arial7_0xdb},
// character: 'Ü'
  {0xdc, &Arial7_0xdc},
// character: 'Ý'
  {0xdd, &Arial7_0xdd},
// character: 'Þ'
  {0xde, &Arial7_0xde},
// character: 'ß'
  {0xdf, &Arial7_0xdf},
// character: 'à'
  {0xe0, &Arial7_0xe0},
// character: 'á'
  {0xe1, &Arial7_0xe1},
// character: 'â'
  {0xe2, &Arial7_0xe2},
// character: 'ã'
  {0xe3, &Arial7_0xe3},
// character: 'ä'
  {0xe4, &Arial7_0xe4},
// character: 'å'
  {0xe5, &Arial7_0xe5},
// character: 'æ'
  {0xe6, &Arial7_0xe6},
// character: 'ç'
  {0xe7, &Arial7_0xe7},
// character: 'è'
  {0xe8, &Arial7_0xe8},
// character: 'é'
  {0xe9, &Arial7_0xe9},
// character: 'ê'
  {0xea, &Arial7_0xea},
// character: 'ë'
  {0xeb, &Arial7_0xeb},
// character: 'ì'
  {0xec, &Arial7_0xec},
// character: 'í'
  {0xed, &Arial7_0xed},
// character: 'î'
  {0xee, &Arial7_0xee},
// character: 'ï'
  {0xef, &Arial7_0xef},
// character: 'ð'
  {0xf0, &Arial7_0xf0},
// character: 'ñ'
  {0xf1, &Arial7_0xf1},
// character: 'ò'
  {0xf2, &Arial7_0xf2},
// character: 'ó'
  {0xf3, &Arial7_0xf3},
// character: 'ô'
  {0xf4, &Arial7_0xf4},
// character: 'õ'
  {0xf5, &Arial7_0xf5},
// character: 'ö'
  {0xf6, &Arial7_0xf6},
// character: '÷'
  {0xf7, &Arial7_0xf7},
// character: 'ø'
  {0xf8, &Arial7_0xf8},
// character: 'ù'
  {0xf9, &Arial7_0xf9},
// character: 'ú'
  {0xfa, &Arial7_0xfa},
// character: 'û'
  {0xfb, &Arial7_0xfb},
// character: 'ü'
  {0xfc, &Arial7_0xfc},
// character: 'ý'
  {0xfd, &Arial7_0xfd},
// character: 'þ'
  {0xfe, &Arial7_0xfe},
// character: 'ÿ'
  {0xff, &Arial7_0xff},
// character: 'ª'
  {0xaa, &Arial7_0xaa},
// character: '²'
  {0xb2, &Arial7_0xb2},
// character: '¯'
  {0xaf, &Arial7_0xaf},
// character: 'º'
  {0xba, &Arial7_0xba},
// character: '³'
  {0xb3, &Arial7_0xb3},
// character: '¿'
  {0xbf, &Arial7_0xbf}
};

static const tFont Arial7 = { 165, Arial7_array };

#endif /* ARIAL7_H_ */
