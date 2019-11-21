/*
 * arial9_b.h
 *
 *  Created on: 16 ����. 2012
 *      Author: vovan
 */

#ifndef ARIAL9_B_H_
#define ARIAL9_B_H_

/*******************************************************************************
* filename: /home/vovan/document/arial9_b.xml
* name: Arial9_b
* family: Arial
* size: 9
* style: Negreta
* included characters:  !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~����������������������������������������������������������������������
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


static const uint8_t image_data_Arial9_b_0x20[7] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const tImage Arial9_b_0x20 = { image_data_Arial9_b_0x20, 6, 9};//' '
static const uint8_t image_data_Arial9_b_0x21[3] = {
    0xff, 0xf3, 0xc0
};
static const tImage Arial9_b_0x21 = { image_data_Arial9_b_0x21, 2, 9};//'!'
static const uint8_t image_data_Arial9_b_0x22[6] = {
    0xde, 0xf6, 0x00, 0x00, 0x00, 0x00
};
static const tImage Arial9_b_0x22 = { image_data_Arial9_b_0x22, 5, 9};//'"'
static const uint8_t image_data_Arial9_b_0x23[7] = {
    0x24, 0x9f, 0xd2, 0x4b, 0xf4, 0xa4, 0x90
};
static const tImage Arial9_b_0x23 = { image_data_Arial9_b_0x23, 6, 9};//'#'
static const uint8_t image_data_Arial9_b_0x24[6] = {
    0x75, 0x69, 0xc7, 0x1c, 0xb5, 0x70
};
static const tImage Arial9_b_0x24 = { image_data_Arial9_b_0x24, 5, 9};//'$'
static const uint8_t image_data_Arial9_b_0x25[9] = {
    0xe4, 0xa4, 0xa8, 0xa8, 0xef, 0x15, 0x15, 0x25, 0x27
};
static const tImage Arial9_b_0x25 = { image_data_Arial9_b_0x25, 8, 9};//'%'
static const uint8_t image_data_Arial9_b_0x26[11] = {
    0x38, 0x36, 0x1b, 0x07, 0x07, 0x06, 0xdb, 0x39, 0x9e, 0x7b, 0x80
};
static const tImage Arial9_b_0x26 = { image_data_Arial9_b_0x26, 9, 9};//'&'
static const uint8_t image_data_Arial9_b_0x27[3] = {
    0xfc, 0x00, 0x00
};
static const tImage Arial9_b_0x27 = { image_data_Arial9_b_0x27, 2, 9};//'''
static const uint8_t image_data_Arial9_b_0x28[3] = {
    0x7a, 0xab, 0x40
};
static const tImage Arial9_b_0x28 = { image_data_Arial9_b_0x28, 2, 9};//'('
static const uint8_t image_data_Arial9_b_0x29[3] = {
    0xb5, 0x57, 0x80
};
static const tImage Arial9_b_0x29 = { image_data_Arial9_b_0x29, 2, 9};//')'
static const uint8_t image_data_Arial9_b_0x2a[4] = {
    0x5d, 0x50, 0x00, 0x00
};
static const tImage Arial9_b_0x2a = { image_data_Arial9_b_0x2a, 3, 9};//'*'
static const uint8_t image_data_Arial9_b_0x2b[7] = {
    0x00, 0x03, 0x0c, 0xfc, 0xc3, 0x00, 0x00
};
static const tImage Arial9_b_0x2b = { image_data_Arial9_b_0x2b, 6, 9};//'+'
static const uint8_t image_data_Arial9_b_0x2c[3] = {
    0x00, 0x3d, 0x80
};
static const tImage Arial9_b_0x2c = { image_data_Arial9_b_0x2c, 2, 9};//','
static const uint8_t image_data_Arial9_b_0x2d[7] = {
    0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00
};
static const tImage Arial9_b_0x2d = { image_data_Arial9_b_0x2d, 6, 9};//'-'
static const uint8_t image_data_Arial9_b_0x2e[7] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x30
};
static const tImage Arial9_b_0x2e = { image_data_Arial9_b_0x2e, 6, 9};//'.'
static const uint8_t image_data_Arial9_b_0x2f[4] = {
    0x25, 0x24, 0x94, 0x80
};
static const tImage Arial9_b_0x2f = { image_data_Arial9_b_0x2f, 3, 9};//'/'
static const uint8_t image_data_Arial9_b_0x30[7] = {
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x78
};
static const tImage Arial9_b_0x30 = { image_data_Arial9_b_0x30, 6, 9};//'0'
static const uint8_t image_data_Arial9_b_0x31[7] = {
    0x18, 0xe7, 0x96, 0x18, 0x61, 0x86, 0x18
};
static const tImage Arial9_b_0x31 = { image_data_Arial9_b_0x31, 6, 9};//'1'
static const uint8_t image_data_Arial9_b_0x32[7] = {
    0x7b, 0x30, 0xc3, 0x18, 0xc6, 0x30, 0xfc
};
static const tImage Arial9_b_0x32 = { image_data_Arial9_b_0x32, 6, 9};//'2'
static const uint8_t image_data_Arial9_b_0x33[7] = {
    0x7b, 0x30, 0xce, 0x0c, 0x30, 0xf3, 0x78
};
static const tImage Arial9_b_0x33 = { image_data_Arial9_b_0x33, 6, 9};//'3'
static const uint8_t image_data_Arial9_b_0x34[7] = {
    0x18, 0xe3, 0x96, 0x5a, 0x6f, 0xc6, 0x18
};
static const tImage Arial9_b_0x34 = { image_data_Arial9_b_0x34, 6, 9};//'4'
static const uint8_t image_data_Arial9_b_0x35[7] = {
    0xff, 0x0c, 0x3e, 0xcc, 0x30, 0xf3, 0x78
};
static const tImage Arial9_b_0x35 = { image_data_Arial9_b_0x35, 6, 9};//'5'
static const uint8_t image_data_Arial9_b_0x36[7] = {
    0x7b, 0x3c, 0x3e, 0xcf, 0x3c, 0xf3, 0x78
};
static const tImage Arial9_b_0x36 = { image_data_Arial9_b_0x36, 6, 9};//'6'
static const uint8_t image_data_Arial9_b_0x37[7] = {
    0xfc, 0x31, 0x86, 0x30, 0xc6, 0x18, 0x60
};
static const tImage Arial9_b_0x37 = { image_data_Arial9_b_0x37, 6, 9};//'7'
static const uint8_t image_data_Arial9_b_0x38[7] = {
    0x7b, 0x3c, 0xf3, 0x7b, 0x3c, 0xf3, 0x78
};
static const tImage Arial9_b_0x38 = { image_data_Arial9_b_0x38, 6, 9};//'8'
static const uint8_t image_data_Arial9_b_0x39[7] = {
    0x7b, 0x3c, 0xf3, 0xcd, 0xf0, 0xf3, 0x78
};
static const tImage Arial9_b_0x39 = { image_data_Arial9_b_0x39, 6, 9};//'9'
static const uint8_t image_data_Arial9_b_0x3a[3] = {
    0x3c, 0x0f, 0x00
};
static const tImage Arial9_b_0x3a = { image_data_Arial9_b_0x3a, 2, 9};//':'
static const uint8_t image_data_Arial9_b_0x3b[3] = {
    0x3c, 0x3d, 0x80
};
static const tImage Arial9_b_0x3b = { image_data_Arial9_b_0x3b, 2, 9};//';'
static const uint8_t image_data_Arial9_b_0x3c[5] = {
    0x01, 0x37, 0xf7, 0x31, 0x00
};
static const tImage Arial9_b_0x3c = { image_data_Arial9_b_0x3c, 4, 9};//'<'
static const uint8_t image_data_Arial9_b_0x3d[7] = {
    0x00, 0x00, 0x3f, 0x03, 0xf0, 0x00, 0x00
};
static const tImage Arial9_b_0x3d = { image_data_Arial9_b_0x3d, 6, 9};//'='
static const uint8_t image_data_Arial9_b_0x3e[7] = {
    0x02, 0x0e, 0x0e, 0x0c, 0xee, 0x20, 0x00
};
static const tImage Arial9_b_0x3e = { image_data_Arial9_b_0x3e, 6, 9};//'>'
static const uint8_t image_data_Arial9_b_0x3f[7] = {
    0x7b, 0x30, 0xc6, 0x30, 0xc0, 0x0c, 0x30
};
static const tImage Arial9_b_0x3f = { image_data_Arial9_b_0x3f, 6, 9};//'?'
static const uint8_t image_data_Arial9_b_0x40[11] = {
    0x3e, 0x20, 0xa7, 0x34, 0x9a, 0x4d, 0x26, 0x74, 0x84, 0x3e, 0x00
};
static const tImage Arial9_b_0x40 = { image_data_Arial9_b_0x40, 9, 9};//'(a)'
static const uint8_t image_data_Arial9_b_0x41[8] = {
    0x38, 0x71, 0xb3, 0x66, 0xcd, 0xbf, 0xe3, 0xc6
};
static const tImage Arial9_b_0x41 = { image_data_Arial9_b_0x41, 7, 9};//'A'
static const uint8_t image_data_Arial9_b_0x42[8] = {
    0xfd, 0x8f, 0x1e, 0x3f, 0xd8, 0xf1, 0xe3, 0xfc
};
static const tImage Arial9_b_0x42 = { image_data_Arial9_b_0x42, 7, 9};//'B'
static const uint8_t image_data_Arial9_b_0x43[8] = {
    0x3c, 0xcf, 0x06, 0x0c, 0x18, 0x30, 0x33, 0x3c
};
static const tImage Arial9_b_0x43 = { image_data_Arial9_b_0x43, 7, 9};//'C'
static const uint8_t image_data_Arial9_b_0x44[8] = {
    0xf9, 0x9b, 0x1e, 0x3c, 0x78, 0xf1, 0xe6, 0xf8
};
static const tImage Arial9_b_0x44 = { image_data_Arial9_b_0x44, 7, 9};//'D'
static const uint8_t image_data_Arial9_b_0x45[7] = {
    0xff, 0x0c, 0x30, 0xff, 0x0c, 0x30, 0xfc
};
static const tImage Arial9_b_0x45 = { image_data_Arial9_b_0x45, 6, 9};//'E'
static const uint8_t image_data_Arial9_b_0x46[6] = {
    0xfe, 0x31, 0x8f, 0xe3, 0x18, 0xc0
};
static const tImage Arial9_b_0x46 = { image_data_Arial9_b_0x46, 5, 9};//'F'
static const uint8_t image_data_Arial9_b_0x47[8] = {
    0x3c, 0xcf, 0x06, 0x0c, 0xf8, 0xf1, 0xb3, 0x3c
};
static const tImage Arial9_b_0x47 = { image_data_Arial9_b_0x47, 7, 9};//'G'
static const uint8_t image_data_Arial9_b_0x48[8] = {
    0xc7, 0x8f, 0x1e, 0x3f, 0xf8, 0xf1, 0xe3, 0xc6
};
static const tImage Arial9_b_0x48 = { image_data_Arial9_b_0x48, 7, 9};//'H'
static const uint8_t image_data_Arial9_b_0x49[3] = {
    0xff, 0xff, 0xc0
};
static const tImage Arial9_b_0x49 = { image_data_Arial9_b_0x49, 2, 9};//'I'
static const uint8_t image_data_Arial9_b_0x4a[7] = {
    0x0c, 0x30, 0xc3, 0x0c, 0x3c, 0xf3, 0x78
};
static const tImage Arial9_b_0x4a = { image_data_Arial9_b_0x4a, 6, 9};//'J'
static const uint8_t image_data_Arial9_b_0x4b[8] = {
    0xc7, 0x9b, 0x67, 0xcf, 0xd9, 0xb3, 0x63, 0xc6
};
static const tImage Arial9_b_0x4b = { image_data_Arial9_b_0x4b, 7, 9};//'K'
static const uint8_t image_data_Arial9_b_0x4c[7] = {
    0xc3, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0xfc
};
static const tImage Arial9_b_0x4c = { image_data_Arial9_b_0x4c, 6, 9};//'L'
static const uint8_t image_data_Arial9_b_0x4d[11] = {
    0xe3, 0xf1, 0xfd, 0xfe, 0xfd, 0x5e, 0xaf, 0x77, 0xbb, 0xc9, 0x80
};
static const tImage Arial9_b_0x4d = { image_data_Arial9_b_0x4d, 9, 9};//'M'
static const uint8_t image_data_Arial9_b_0x4e[8] = {
    0xc7, 0xcf, 0x9f, 0xbd, 0x7b, 0xf3, 0xe7, 0xc6
};
static const tImage Arial9_b_0x4e = { image_data_Arial9_b_0x4e, 7, 9};//'N'
static const uint8_t image_data_Arial9_b_0x4f[9] = {
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c
};
static const tImage Arial9_b_0x4f = { image_data_Arial9_b_0x4f, 8, 9};//'O'
static const uint8_t image_data_Arial9_b_0x50[8] = {
    0xfd, 0x8f, 0x1e, 0x3c, 0x7f, 0xb0, 0x60, 0xc0
};
static const tImage Arial9_b_0x50 = { image_data_Arial9_b_0x50, 7, 9};//'P'
static const uint8_t image_data_Arial9_b_0x51[9] = {
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xcb, 0x66, 0x3d
};
static const tImage Arial9_b_0x51 = { image_data_Arial9_b_0x51, 8, 9};//'Q'
static const uint8_t image_data_Arial9_b_0x52[9] = {
    0xfc, 0xc6, 0xc6, 0xc6, 0xfc, 0xcc, 0xc6, 0xc6, 0xc3
};
static const tImage Arial9_b_0x52 = { image_data_Arial9_b_0x52, 8, 9};//'R'
static const uint8_t image_data_Arial9_b_0x53[8] = {
    0x7d, 0x8f, 0x07, 0x87, 0xc3, 0xc1, 0xe3, 0x7c
};
static const tImage Arial9_b_0x53 = { image_data_Arial9_b_0x53, 7, 9};//'S'
static const uint8_t image_data_Arial9_b_0x54[7] = {
    0xfc, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 0x30
};
static const tImage Arial9_b_0x54 = { image_data_Arial9_b_0x54, 6, 9};//'T'
static const uint8_t image_data_Arial9_b_0x55[8] = {
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x7c
};
static const tImage Arial9_b_0x55 = { image_data_Arial9_b_0x55, 7, 9};//'U'
static const uint8_t image_data_Arial9_b_0x56[11] = {
    0xc1, 0xb1, 0x98, 0xcc, 0x63, 0x61, 0xb0, 0xd8, 0x38, 0x1c, 0x00
};
static const tImage Arial9_b_0x56 = { image_data_Arial9_b_0x56, 9, 9};//'V'
static const uint8_t image_data_Arial9_b_0x57[15] = {
    0xc7, 0x1e, 0x38, 0xdb, 0xec, 0xdb, 0x66, 0xdb, 0x36, 0xd8, 0xe3, 0x87, 0x1c, 0x38, 0xe0
};
static const tImage Arial9_b_0x57 = { image_data_Arial9_b_0x57, 13, 9};//'W'
static const uint8_t image_data_Arial9_b_0x58[8] = {
    0xc7, 0x8d, 0xb3, 0xe3, 0x8f, 0x9b, 0x63, 0xc6
};
static const tImage Arial9_b_0x58 = { image_data_Arial9_b_0x58, 7, 9};//'X'
static const uint8_t image_data_Arial9_b_0x59[9] = {
    0xc3, 0x66, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18
};
static const tImage Arial9_b_0x59 = { image_data_Arial9_b_0x59, 8, 9};//'Y'
static const uint8_t image_data_Arial9_b_0x5a[7] = {
    0xfc, 0x31, 0x8c, 0x31, 0x8c, 0x30, 0xfc
};
static const tImage Arial9_b_0x5a = { image_data_Arial9_b_0x5a, 6, 9};//'Z'
static const uint8_t image_data_Arial9_b_0x5b[4] = {
    0xfb, 0x6d, 0xb6, 0xe0
};
static const tImage Arial9_b_0x5b = { image_data_Arial9_b_0x5b, 3, 9};//'['
static const uint8_t image_data_Arial9_b_0x5c[4] = {
    0x91, 0x24, 0x91, 0x20
};
static const tImage Arial9_b_0x5c = { image_data_Arial9_b_0x5c, 3, 9};//'\'
static const uint8_t image_data_Arial9_b_0x5d[4] = {
    0xed, 0xb6, 0xdb, 0xe0
};
static const tImage Arial9_b_0x5d = { image_data_Arial9_b_0x5d, 3, 9};//']'
static const uint8_t image_data_Arial9_b_0x5e[6] = {
    0x76, 0xf7, 0xb7, 0x00, 0x00, 0x00
};
static const tImage Arial9_b_0x5e = { image_data_Arial9_b_0x5e, 5, 9};//'^'
static const uint8_t image_data_Arial9_b_0x5f[8] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe
};
static const tImage Arial9_b_0x5f = { image_data_Arial9_b_0x5f, 7, 9};//'_'
static const uint8_t image_data_Arial9_b_0x60[4] = {
    0xcc, 0x00, 0x00, 0x00
};
static const tImage Arial9_b_0x60 = { image_data_Arial9_b_0x60, 3, 9};//'`'
static const uint8_t image_data_Arial9_b_0x61[7] = {
    0x00, 0x07, 0xa3, 0x3d, 0xbc, 0xf3, 0x7c
};
static const tImage Arial9_b_0x61 = { image_data_Arial9_b_0x61, 6, 9};//'a'
static const uint8_t image_data_Arial9_b_0x62[7] = {
    0xc3, 0x0d, 0xbb, 0xcf, 0x3c, 0xfb, 0xd8
};
static const tImage Arial9_b_0x62 = { image_data_Arial9_b_0x62, 6, 9};//'b'
static const uint8_t image_data_Arial9_b_0x63[7] = {
    0x00, 0x07, 0xb3, 0xc3, 0x0c, 0x33, 0x78
};
static const tImage Arial9_b_0x63 = { image_data_Arial9_b_0x63, 6, 9};//'c'
static const uint8_t image_data_Arial9_b_0x64[7] = {
    0x0c, 0x36, 0xf7, 0xcf, 0x3c, 0xf7, 0x6c
};
static const tImage Arial9_b_0x64 = { image_data_Arial9_b_0x64, 6, 9};//'d'
static const uint8_t image_data_Arial9_b_0x65[7] = {
    0x00, 0x07, 0xb3, 0xcf, 0xfc, 0x33, 0x78
};
static const tImage Arial9_b_0x65 = { image_data_Arial9_b_0x65, 6, 9};//'e'
static const uint8_t image_data_Arial9_b_0x66[5] = {
    0x7c, 0xec, 0xcc, 0xcc, 0xc0
};
static const tImage Arial9_b_0x66 = { image_data_Arial9_b_0x66, 4, 9};//'f'
static const uint8_t image_data_Arial9_b_0x67[7] = {
    0x00, 0x06, 0xf7, 0xcf, 0x76, 0xe3, 0x78
};
static const tImage Arial9_b_0x67 = { image_data_Arial9_b_0x67, 6, 9};//'g'
static const uint8_t image_data_Arial9_b_0x68[7] = {
    0xc3, 0x0d, 0xbb, 0xcf, 0x3c, 0xf3, 0xcc
};
static const tImage Arial9_b_0x68 = { image_data_Arial9_b_0x68, 6, 9};//'h'
static const uint8_t image_data_Arial9_b_0x69[3] = {
    0xcf, 0xff, 0xc0
};
static const tImage Arial9_b_0x69 = { image_data_Arial9_b_0x69, 2, 9};//'i'
static const uint8_t image_data_Arial9_b_0x6a[4] = {
    0x61, 0xb6, 0xdb, 0xe0
};
static const tImage Arial9_b_0x6a = { image_data_Arial9_b_0x6a, 3, 9};//'j'
static const uint8_t image_data_Arial9_b_0x6b[7] = {
    0xc3, 0x0c, 0xf6, 0xf3, 0xed, 0xb3, 0xcc
};
static const tImage Arial9_b_0x6b = { image_data_Arial9_b_0x6b, 6, 9};//'k'
static const uint8_t image_data_Arial9_b_0x6c[3] = {
    0xff, 0xff, 0xc0
};
static const tImage Arial9_b_0x6c = { image_data_Arial9_b_0x6c, 2, 9};//'l'
static const uint8_t image_data_Arial9_b_0x6d[12] = {
    0x00, 0x00, 0x0d, 0xdb, 0xbb, 0xcc, 0xf3, 0x3c, 0xcf, 0x33, 0xcc, 0xc0
};
static const tImage Arial9_b_0x6d = { image_data_Arial9_b_0x6d, 10, 9};//'m'
static const uint8_t image_data_Arial9_b_0x6e[7] = {
    0x00, 0x0d, 0xbb, 0xcf, 0x3c, 0xf3, 0xcc
};
static const tImage Arial9_b_0x6e = { image_data_Arial9_b_0x6e, 6, 9};//'n'
static const uint8_t image_data_Arial9_b_0x6f[7] = {
    0x00, 0x07, 0xb3, 0xcf, 0x3c, 0xf3, 0x78
};
static const tImage Arial9_b_0x6f = { image_data_Arial9_b_0x6f, 6, 9};//'o'
static const uint8_t image_data_Arial9_b_0x70[7] = {
    0x00, 0x0d, 0xbb, 0xcf, 0x3e, 0xf6, 0xc0
};
static const tImage Arial9_b_0x70 = { image_data_Arial9_b_0x70, 6, 9};//'p'
static const uint8_t image_data_Arial9_b_0x71[7] = {
    0x00, 0x06, 0xf7, 0xcf, 0x3d, 0xdb, 0x0c
};
static const tImage Arial9_b_0x71 = { image_data_Arial9_b_0x71, 6, 9};//'q'
static const uint8_t image_data_Arial9_b_0x72[6] = {
    0x00, 0x37, 0xcc, 0x63, 0x18, 0xc0
};
static const tImage Arial9_b_0x72 = { image_data_Arial9_b_0x72, 5, 9};//'r'
static const uint8_t image_data_Arial9_b_0x73[7] = {
    0x00, 0x07, 0xb3, 0xe1, 0xe1, 0xf3, 0x78
};
static const tImage Arial9_b_0x73 = { image_data_Arial9_b_0x73, 6, 9};//'s'
static const uint8_t image_data_Arial9_b_0x74[5] = {
    0x66, 0xf6, 0x66, 0x66, 0x30
};
static const tImage Arial9_b_0x74 = { image_data_Arial9_b_0x74, 4, 9};//'t'
static const uint8_t image_data_Arial9_b_0x75[7] = {
    0x00, 0x0c, 0xf3, 0xcf, 0x3c, 0xf7, 0x6c
};
static const tImage Arial9_b_0x75 = { image_data_Arial9_b_0x75, 6, 9};//'u'
static const uint8_t image_data_Arial9_b_0x76[8] = {
    0x00, 0x03, 0x1e, 0x36, 0xcd, 0x9b, 0x1c, 0x38
};
static const tImage Arial9_b_0x76 = { image_data_Arial9_b_0x76, 7, 9};//'v'
static const uint8_t image_data_Arial9_b_0x77[11] = {
    0x00, 0x00, 0x32, 0x7b, 0xbd, 0xde, 0xad, 0xdc, 0xee, 0x63, 0x00
};
static const tImage Arial9_b_0x77 = { image_data_Arial9_b_0x77, 9, 9};//'w'
static const uint8_t image_data_Arial9_b_0x78[7] = {
    0x00, 0x0c, 0xf3, 0x78, 0xc7, 0xb3, 0xcc
};
static const tImage Arial9_b_0x78 = { image_data_Arial9_b_0x78, 6, 9};//'x'
static const uint8_t image_data_Arial9_b_0x79[8] = {
    0x01, 0x8d, 0xb3, 0x62, 0x87, 0x04, 0x08, 0x60
};
static const tImage Arial9_b_0x79 = { image_data_Arial9_b_0x79, 7, 9};//'y'
static const uint8_t image_data_Arial9_b_0x7a[6] = {
    0x00, 0x3e, 0x33, 0x31, 0x98, 0xf8
};
static const tImage Arial9_b_0x7a = { image_data_Arial9_b_0x7a, 5, 9};//'z'
static const uint8_t image_data_Arial9_b_0x7b[6] = {
    0x3b, 0x18, 0xcc, 0x31, 0x8c, 0x38
};
static const tImage Arial9_b_0x7b = { image_data_Arial9_b_0x7b, 5, 9};//'{'
static const uint8_t image_data_Arial9_b_0x7c[3] = {
    0x55, 0x55, 0x40
};
static const tImage Arial9_b_0x7c = { image_data_Arial9_b_0x7c, 2, 9};//'|'
static const uint8_t image_data_Arial9_b_0x7d[5] = {
    0xc6, 0x66, 0x36, 0x66, 0xc0
};
static const tImage Arial9_b_0x7d = { image_data_Arial9_b_0x7d, 4, 9};//'}'
static const uint8_t image_data_Arial9_b_0x7e[7] = {
    0x00, 0x00, 0x19, 0x98, 0x00, 0x00, 0x00
};
static const tImage Arial9_b_0x7e = { image_data_Arial9_b_0x7e, 6, 9};//'~'
static const uint8_t image_data_Arial9_b_0xaa[9] = {
    0x3c, 0x66, 0xc3, 0xc0, 0xf8, 0xc0, 0xc3, 0x66, 0x3c
};
static const tImage Arial9_b_0xaa = { image_data_Arial9_b_0xaa, 8, 9};//'�'
static const uint8_t image_data_Arial9_b_0xb2[3] = {
    0xff, 0xff, 0xc0
};
static const tImage Arial9_b_0xb2 = { image_data_Arial9_b_0xb2, 2, 9};//'�'
static const uint8_t image_data_Arial9_b_0xaf[5] = {
    0x99, 0x66, 0x66, 0x66, 0x60
};
static const tImage Arial9_b_0xaf = { image_data_Arial9_b_0xaf, 4, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc0[8] = {
    0x38, 0x71, 0xb3, 0x66, 0xcd, 0xbf, 0xe3, 0xc6
};
static const tImage Arial9_b_0xc0 = { image_data_Arial9_b_0xc0, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc1[8] = {
    0xfd, 0x83, 0x07, 0xec, 0x78, 0xf1, 0xe3, 0xfc
};
static const tImage Arial9_b_0xc1 = { image_data_Arial9_b_0xc1, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc2[8] = {
    0xfd, 0x8f, 0x1e, 0x3f, 0xd8, 0xf1, 0xe3, 0xfc
};
static const tImage Arial9_b_0xc2 = { image_data_Arial9_b_0xc2, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc3[7] = {
    0xff, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0xc0
};
static const tImage Arial9_b_0xc3 = { image_data_Arial9_b_0xc3, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc4[9] = {
    0x3e, 0x36, 0x36, 0x36, 0x36, 0x36, 0x66, 0x66, 0xff
};
static const tImage Arial9_b_0xc4 = { image_data_Arial9_b_0xc4, 8, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc5[7] = {
    0xff, 0x0c, 0x30, 0xff, 0x0c, 0x30, 0xfc
};
static const tImage Arial9_b_0xc5 = { image_data_Arial9_b_0xc5, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc6[12] = {
    0xcc, 0xdb, 0x66, 0xd8, 0xb4, 0x3f, 0x1b, 0x66, 0xd9, 0xb6, 0xcc, 0xc0
};
static const tImage Arial9_b_0xc6 = { image_data_Arial9_b_0xc6, 10, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc7[8] = {
    0x7d, 0x8c, 0x18, 0xe0, 0x60, 0xc1, 0xe3, 0x7c
};
static const tImage Arial9_b_0xc7 = { image_data_Arial9_b_0xc7, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc8[8] = {
    0xc7, 0x9f, 0x3e, 0xfd, 0x7e, 0xf9, 0xf3, 0xc6
};
static const tImage Arial9_b_0xc8 = { image_data_Arial9_b_0xc8, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xc9[8] = {
    0x39, 0x9f, 0x3e, 0xfd, 0x7e, 0xf9, 0xf3, 0xc6
};
static const tImage Arial9_b_0xc9 = { image_data_Arial9_b_0xc9, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xca[7] = {
    0xcf, 0x6d, 0xb4, 0xf3, 0x6d, 0xb6, 0xcc
};
static const tImage Arial9_b_0xca = { image_data_Arial9_b_0xca, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xcb[8] = {
    0x06, 0x1c, 0x79, 0xb6, 0x6c, 0xd9, 0xb3, 0xc6
};
static const tImage Arial9_b_0xcb = { image_data_Arial9_b_0xcb, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xcc[11] = {
    0xe3, 0xf1, 0xfd, 0xfe, 0xfd, 0x5e, 0xaf, 0x77, 0xbb, 0xc9, 0x80
};
static const tImage Arial9_b_0xcc = { image_data_Arial9_b_0xcc, 9, 9};//'�'
static const uint8_t image_data_Arial9_b_0xcd[8] = {
    0xc7, 0x8f, 0x1e, 0x3f, 0xf8, 0xf1, 0xe3, 0xc6
};
static const tImage Arial9_b_0xcd = { image_data_Arial9_b_0xcd, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xce[9] = {
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c
};
static const tImage Arial9_b_0xce = { image_data_Arial9_b_0xce, 8, 9};//'�'
static const uint8_t image_data_Arial9_b_0xcf[9] = {
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3
};
static const tImage Arial9_b_0xcf = { image_data_Arial9_b_0xcf, 8, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd0[8] = {
    0xfd, 0x8f, 0x1e, 0x3c, 0x7f, 0xb0, 0x60, 0xc0
};
static const tImage Arial9_b_0xd0 = { image_data_Arial9_b_0xd0, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd1[8] = {
    0x3c, 0xcf, 0x06, 0x0c, 0x18, 0x30, 0x33, 0x3c
};
static const tImage Arial9_b_0xd1 = { image_data_Arial9_b_0xd1, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd2[7] = {
    0xfc, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 0x30
};
static const tImage Arial9_b_0xd2 = { image_data_Arial9_b_0xd2, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd3[7] = {
    0xcf, 0x3c, 0xf3, 0xfd, 0xe3, 0x1c, 0xe0
};
static const tImage Arial9_b_0xd3 = { image_data_Arial9_b_0xd3, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd4[12] = {
    0x0c, 0x0f, 0xc6, 0xdb, 0x33, 0xcc, 0xf3, 0x36, 0xd8, 0xfc, 0x0c, 0x00
};
static const tImage Arial9_b_0xd4 = { image_data_Arial9_b_0xd4, 10, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd5[8] = {
    0xc7, 0x8d, 0xb3, 0xe3, 0x8f, 0x9b, 0x63, 0xc6
};
static const tImage Arial9_b_0xd5 = { image_data_Arial9_b_0xd5, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd6[8] = {
    0xcd, 0x9b, 0x36, 0x6c, 0xd9, 0xbf, 0xff, 0x02
};
static const tImage Arial9_b_0xd6 = { image_data_Arial9_b_0xd6, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd7[8] = {
    0xc7, 0x8f, 0x1e, 0x3c, 0x6f, 0xc1, 0x83, 0x06
};
static const tImage Arial9_b_0xd7 = { image_data_Arial9_b_0xd7, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd8[12] = {
    0xcc, 0xf3, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 0x3c, 0xcf, 0x33, 0xff, 0xc0
};
static const tImage Arial9_b_0xd8 = { image_data_Arial9_b_0xd8, 10, 9};//'�'
static const uint8_t image_data_Arial9_b_0xd9[13] = {
    0xcc, 0xd9, 0x9b, 0x33, 0x66, 0x6c, 0xcd, 0x99, 0xbf, 0xff, 0xff, 0x00, 0x20
};
static const tImage Arial9_b_0xd9 = { image_data_Arial9_b_0xd9, 11, 9};//'�'
static const uint8_t image_data_Arial9_b_0xda[11] = {
    0xf0, 0x18, 0x0c, 0x06, 0x03, 0xf1, 0x8c, 0xc6, 0x63, 0x3f, 0x00
};
static const tImage Arial9_b_0xda = { image_data_Arial9_b_0xda, 9, 9};//'�'
static const uint8_t image_data_Arial9_b_0xdb[13] = {
    0xc0, 0x78, 0x0f, 0x01, 0xe0, 0x3f, 0xc7, 0x8c, 0xf1, 0x9e, 0x33, 0xfc, 0x60
};
static const tImage Arial9_b_0xdb = { image_data_Arial9_b_0xdb, 11, 9};//'�'
static const uint8_t image_data_Arial9_b_0xdc[8] = {
    0xc1, 0x83, 0x06, 0x0f, 0xd8, 0xf1, 0xe3, 0xfc
};
static const tImage Arial9_b_0xdc = { image_data_Arial9_b_0xdc, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xdd[9] = {
    0x3c, 0x66, 0xc3, 0x03, 0x1f, 0x03, 0xc3, 0x66, 0x3c
};
static const tImage Arial9_b_0xdd = { image_data_Arial9_b_0xdd, 8, 9};//'�'
static const uint8_t image_data_Arial9_b_0xde[13] = {
    0xc7, 0x99, 0x9b, 0x61, 0xec, 0x3f, 0x87, 0xb0, 0xf6, 0x1e, 0x66, 0xc7, 0x80
};
static const tImage Arial9_b_0xde = { image_data_Arial9_b_0xde, 11, 9};//'�'
static const uint8_t image_data_Arial9_b_0xdf[8] = {
    0x7f, 0x8f, 0x1e, 0x37, 0xec, 0xf1, 0xe3, 0x86
};
static const tImage Arial9_b_0xdf = { image_data_Arial9_b_0xdf, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe0[7] = {
    0x00, 0x07, 0xa3, 0x3d, 0xbc, 0xf3, 0x7c
};
static const tImage Arial9_b_0xe0 = { image_data_Arial9_b_0xe0, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe1[7] = {
    0x7e, 0x0b, 0xb3, 0xcf, 0x3c, 0xf3, 0x78
};
static const tImage Arial9_b_0xe1 = { image_data_Arial9_b_0xe1, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe2[7] = {
    0x00, 0x0f, 0xb3, 0xcf, 0xec, 0xf3, 0xf8
};
static const tImage Arial9_b_0xe2 = { image_data_Arial9_b_0xe2, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe3[5] = {
    0x00, 0xfc, 0xcc, 0xcc, 0xc0
};
static const tImage Arial9_b_0xe3 = { image_data_Arial9_b_0xe3, 4, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe4[8] = {
    0x00, 0x00, 0xf3, 0x66, 0xcd, 0x9b, 0x36, 0xfe
};
static const tImage Arial9_b_0xe4 = { image_data_Arial9_b_0xe4, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe5[7] = {
    0x00, 0x07, 0xb3, 0xcf, 0xfc, 0x33, 0x78
};
static const tImage Arial9_b_0xe5 = { image_data_Arial9_b_0xe5, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe6[9] = {
    0x00, 0x00, 0xdb, 0x5a, 0x5a, 0x3c, 0x5a, 0xdb, 0xdb
};
static const tImage Arial9_b_0xe6 = { image_data_Arial9_b_0xe6, 8, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe7[6] = {
    0x00, 0x1d, 0xb1, 0x98, 0x7b, 0x70
};
static const tImage Arial9_b_0xe7 = { image_data_Arial9_b_0xe7, 5, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe8[7] = {
    0x00, 0x0c, 0xf7, 0xdf, 0x7e, 0xfb, 0xcc
};
static const tImage Arial9_b_0xe8 = { image_data_Arial9_b_0xe8, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xe9[7] = {
    0x30, 0x0c, 0xf7, 0xdf, 0x7e, 0xfb, 0xcc
};
static const tImage Arial9_b_0xe9 = { image_data_Arial9_b_0xe9, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xea[7] = {
    0x00, 0x0c, 0xf6, 0xd3, 0xcd, 0xb6, 0xcc
};
static const tImage Arial9_b_0xea = { image_data_Arial9_b_0xea, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xeb[8] = {
    0x00, 0x00, 0x79, 0xf7, 0x6c, 0xd9, 0xb3, 0xc6
};
static const tImage Arial9_b_0xeb = { image_data_Arial9_b_0xeb, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xec[8] = {
    0x00, 0x03, 0x1e, 0x3e, 0xfd, 0xee, 0xdd, 0x92
};
static const tImage Arial9_b_0xec = { image_data_Arial9_b_0xec, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xed[7] = {
    0x00, 0x0c, 0xf3, 0xcf, 0xfc, 0xf3, 0xcc
};
static const tImage Arial9_b_0xed = { image_data_Arial9_b_0xed, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xee[7] = {
    0x00, 0x07, 0xb3, 0xcf, 0x3c, 0xf3, 0x78
};
static const tImage Arial9_b_0xee = { image_data_Arial9_b_0xee, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xef[7] = {
    0x00, 0x0f, 0xf3, 0xcf, 0x3c, 0xf3, 0xcc
};
static const tImage Arial9_b_0xef = { image_data_Arial9_b_0xef, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf0[7] = {
    0x00, 0x0d, 0xbb, 0xcf, 0x3e, 0xf6, 0xc0
};
static const tImage Arial9_b_0xf0 = { image_data_Arial9_b_0xf0, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf1[7] = {
    0x00, 0x07, 0xb3, 0xc3, 0x0c, 0x33, 0x78
};
static const tImage Arial9_b_0xf1 = { image_data_Arial9_b_0xf1, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf2[7] = {
    0x00, 0x0f, 0xcc, 0x30, 0xc3, 0x0c, 0x30
};
static const tImage Arial9_b_0xf2 = { image_data_Arial9_b_0xf2, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf3[8] = {
    0x00, 0x03, 0x1f, 0x76, 0xcd, 0x8e, 0x1c, 0x70
};
static const tImage Arial9_b_0xf3 = { image_data_Arial9_b_0xf3, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf4[9] = {
    0x00, 0x00, 0x18, 0x7e, 0xdb, 0x99, 0xdb, 0x7e, 0x18
};
static const tImage Arial9_b_0xf4 = { image_data_Arial9_b_0xf4, 8, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf5[7] = {
    0x00, 0x0c, 0xf3, 0x78, 0xc7, 0xb3, 0xcc
};
static const tImage Arial9_b_0xf5 = { image_data_Arial9_b_0xf5, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf6[8] = {
    0x00, 0x03, 0x36, 0x6c, 0xd9, 0xb3, 0x7f, 0x02
};
static const tImage Arial9_b_0xf6 = { image_data_Arial9_b_0xf6, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf7[7] = {
    0x00, 0x0c, 0xf3, 0xcd, 0xf0, 0xc3, 0x0c
};
static const tImage Arial9_b_0xf7 = { image_data_Arial9_b_0xf7, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf8[9] = {
    0x00, 0x00, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xff
};
static const tImage Arial9_b_0xf8 = { image_data_Arial9_b_0xf8, 8, 9};//'�'
static const uint8_t image_data_Arial9_b_0xf9[11] = {
    0x00, 0x00, 0x36, 0xdb, 0x6d, 0xb6, 0xdb, 0x6d, 0xff, 0x00, 0x80
};
static const tImage Arial9_b_0xf9 = { image_data_Arial9_b_0xf9, 9, 9};//'�'
static const uint8_t image_data_Arial9_b_0xfa[8] = {
    0x00, 0x03, 0x83, 0x06, 0x0f, 0x99, 0xb3, 0x7c
};
static const tImage Arial9_b_0xfa = { image_data_Arial9_b_0xfa, 7, 9};//'�'
static const uint8_t image_data_Arial9_b_0xfb[11] = {
    0x00, 0x00, 0x30, 0x78, 0x3c, 0x1f, 0xcf, 0x37, 0x9b, 0xf9, 0x80
};
static const tImage Arial9_b_0xfb = { image_data_Arial9_b_0xfb, 9, 9};//'�'
static const uint8_t image_data_Arial9_b_0xfc[7] = {
    0x00, 0x0c, 0x30, 0xc3, 0xec, 0xf3, 0xf8
};
static const tImage Arial9_b_0xfc = { image_data_Arial9_b_0xfc, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xfd[7] = {
    0x00, 0x07, 0xb3, 0x0c, 0xf0, 0xf3, 0x78
};
static const tImage Arial9_b_0xfd = { image_data_Arial9_b_0xfd, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xfe[11] = {
    0x00, 0x00, 0x33, 0xdb, 0x3d, 0x9f, 0xcf, 0x67, 0xb3, 0xcf, 0x00
};
static const tImage Arial9_b_0xfe = { image_data_Arial9_b_0xfe, 9, 9};//'�'
static const uint8_t image_data_Arial9_b_0xff[7] = {
    0x00, 0x07, 0xf3, 0xcd, 0xf3, 0xdb, 0xcc
};
static const tImage Arial9_b_0xff = { image_data_Arial9_b_0xff, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xba[7] = {
    0x00, 0x07, 0xb3, 0xc3, 0xcc, 0x33, 0x78
};
static const tImage Arial9_b_0xba = { image_data_Arial9_b_0xba, 6, 9};//'�'
static const uint8_t image_data_Arial9_b_0xb3[3] = {
    0x33, 0xff, 0xc0
};
static const tImage Arial9_b_0xb3 = { image_data_Arial9_b_0xb3, 2, 9};//'�'
static const uint8_t image_data_Arial9_b_0xbf[5] = {
    0x09, 0x96, 0x66, 0x66, 0x60
};
static const tImage Arial9_b_0xbf = { image_data_Arial9_b_0xbf, 4, 9};//'�'

static const tChar Arial9_b_array[] = {

// character: ' '
  {0x20, &Arial9_b_0x20},
// character: '!'
  {0x21, &Arial9_b_0x21},
// character: '"'
  {0x22, &Arial9_b_0x22},
// character: '#'
  {0x23, &Arial9_b_0x23},
// character: '$'
  {0x24, &Arial9_b_0x24},
// character: '%'
  {0x25, &Arial9_b_0x25},
// character: '&'
  {0x26, &Arial9_b_0x26},
// character: '''
  {0x27, &Arial9_b_0x27},
// character: '('
  {0x28, &Arial9_b_0x28},
// character: ')'
  {0x29, &Arial9_b_0x29},
// character: '*'
  {0x2a, &Arial9_b_0x2a},
// character: '+'
  {0x2b, &Arial9_b_0x2b},
// character: ','
  {0x2c, &Arial9_b_0x2c},
// character: '-'
  {0x2d, &Arial9_b_0x2d},
// character: '.'
  {0x2e, &Arial9_b_0x2e},
// character: '/'
  {0x2f, &Arial9_b_0x2f},
// character: '0'
  {0x30, &Arial9_b_0x30},
// character: '1'
  {0x31, &Arial9_b_0x31},
// character: '2'
  {0x32, &Arial9_b_0x32},
// character: '3'
  {0x33, &Arial9_b_0x33},
// character: '4'
  {0x34, &Arial9_b_0x34},
// character: '5'
  {0x35, &Arial9_b_0x35},
// character: '6'
  {0x36, &Arial9_b_0x36},
// character: '7'
  {0x37, &Arial9_b_0x37},
// character: '8'
  {0x38, &Arial9_b_0x38},
// character: '9'
  {0x39, &Arial9_b_0x39},
// character: ':'
  {0x3a, &Arial9_b_0x3a},
// character: ';'
  {0x3b, &Arial9_b_0x3b},
// character: '<'
  {0x3c, &Arial9_b_0x3c},
// character: '='
  {0x3d, &Arial9_b_0x3d},
// character: '>'
  {0x3e, &Arial9_b_0x3e},
// character: '?'
  {0x3f, &Arial9_b_0x3f},
// character: '(a)'
  {0x40, &Arial9_b_0x40},
// character: 'A'
  {0x41, &Arial9_b_0x41},
// character: 'B'
  {0x42, &Arial9_b_0x42},
// character: 'C'
  {0x43, &Arial9_b_0x43},
// character: 'D'
  {0x44, &Arial9_b_0x44},
// character: 'E'
  {0x45, &Arial9_b_0x45},
// character: 'F'
  {0x46, &Arial9_b_0x46},
// character: 'G'
  {0x47, &Arial9_b_0x47},
// character: 'H'
  {0x48, &Arial9_b_0x48},
// character: 'I'
  {0x49, &Arial9_b_0x49},
// character: 'J'
  {0x4a, &Arial9_b_0x4a},
// character: 'K'
  {0x4b, &Arial9_b_0x4b},
// character: 'L'
  {0x4c, &Arial9_b_0x4c},
// character: 'M'
  {0x4d, &Arial9_b_0x4d},
// character: 'N'
  {0x4e, &Arial9_b_0x4e},
// character: 'O'
  {0x4f, &Arial9_b_0x4f},
// character: 'P'
  {0x50, &Arial9_b_0x50},
// character: 'Q'
  {0x51, &Arial9_b_0x51},
// character: 'R'
  {0x52, &Arial9_b_0x52},
// character: 'S'
  {0x53, &Arial9_b_0x53},
// character: 'T'
  {0x54, &Arial9_b_0x54},
// character: 'U'
  {0x55, &Arial9_b_0x55},
// character: 'V'
  {0x56, &Arial9_b_0x56},
// character: 'W'
  {0x57, &Arial9_b_0x57},
// character: 'X'
  {0x58, &Arial9_b_0x58},
// character: 'Y'
  {0x59, &Arial9_b_0x59},
// character: 'Z'
  {0x5a, &Arial9_b_0x5a},
// character: '['
  {0x5b, &Arial9_b_0x5b},
// character: '\'
  {0x5c, &Arial9_b_0x5c},
// character: ']'
  {0x5d, &Arial9_b_0x5d},
// character: '^'
  {0x5e, &Arial9_b_0x5e},
// character: '_'
  {0x5f, &Arial9_b_0x5f},
// character: '`'
  {0x60, &Arial9_b_0x60},
// character: 'a'
  {0x61, &Arial9_b_0x61},
// character: 'b'
  {0x62, &Arial9_b_0x62},
// character: 'c'
  {0x63, &Arial9_b_0x63},
// character: 'd'
  {0x64, &Arial9_b_0x64},
// character: 'e'
  {0x65, &Arial9_b_0x65},
// character: 'f'
  {0x66, &Arial9_b_0x66},
// character: 'g'
  {0x67, &Arial9_b_0x67},
// character: 'h'
  {0x68, &Arial9_b_0x68},
// character: 'i'
  {0x69, &Arial9_b_0x69},
// character: 'j'
  {0x6a, &Arial9_b_0x6a},
// character: 'k'
  {0x6b, &Arial9_b_0x6b},
// character: 'l'
  {0x6c, &Arial9_b_0x6c},
// character: 'm'
  {0x6d, &Arial9_b_0x6d},
// character: 'n'
  {0x6e, &Arial9_b_0x6e},
// character: 'o'
  {0x6f, &Arial9_b_0x6f},
// character: 'p'
  {0x70, &Arial9_b_0x70},
// character: 'q'
  {0x71, &Arial9_b_0x71},
// character: 'r'
  {0x72, &Arial9_b_0x72},
// character: 's'
  {0x73, &Arial9_b_0x73},
// character: 't'
  {0x74, &Arial9_b_0x74},
// character: 'u'
  {0x75, &Arial9_b_0x75},
// character: 'v'
  {0x76, &Arial9_b_0x76},
// character: 'w'
  {0x77, &Arial9_b_0x77},
// character: 'x'
  {0x78, &Arial9_b_0x78},
// character: 'y'
  {0x79, &Arial9_b_0x79},
// character: 'z'
  {0x7a, &Arial9_b_0x7a},
// character: '{'
  {0x7b, &Arial9_b_0x7b},
// character: '|'
  {0x7c, &Arial9_b_0x7c},
// character: '}'
  {0x7d, &Arial9_b_0x7d},
// character: '~'
  {0x7e, &Arial9_b_0x7e},
// character: '�'
  {0xc0, &Arial9_b_0xc0},
// character: '�'
  {0xc1, &Arial9_b_0xc1},
// character: '�'
  {0xc2, &Arial9_b_0xc2},
// character: '�'
  {0xc3, &Arial9_b_0xc3},
// character: '�'
  {0xc4, &Arial9_b_0xc4},
// character: '�'
  {0xc5, &Arial9_b_0xc5},
// character: '�'
  {0xc6, &Arial9_b_0xc6},
// character: '�'
  {0xc7, &Arial9_b_0xc7},
// character: '�'
  {0xc8, &Arial9_b_0xc8},
// character: '�'
  {0xc9, &Arial9_b_0xc9},
// character: '�'
  {0xca, &Arial9_b_0xca},
// character: '�'
  {0xcb, &Arial9_b_0xcb},
// character: '�'
  {0xcc, &Arial9_b_0xcc},
// character: '�'
  {0xcd, &Arial9_b_0xcd},
// character: '�'
  {0xce, &Arial9_b_0xce},
// character: '�'
  {0xcf, &Arial9_b_0xcf},
// character: '�'
  {0xd0, &Arial9_b_0xd0},
// character: '�'
  {0xd1, &Arial9_b_0xd1},
// character: '�'
  {0xd2, &Arial9_b_0xd2},
// character: '�'
  {0xd3, &Arial9_b_0xd3},
// character: '�'
  {0xd4, &Arial9_b_0xd4},
// character: '�'
  {0xd5, &Arial9_b_0xd5},
// character: '�'
  {0xd6, &Arial9_b_0xd6},
// character: '�'
  {0xd7, &Arial9_b_0xd7},
// character: '�'
  {0xd8, &Arial9_b_0xd8},
// character: '�'
  {0xd9, &Arial9_b_0xd9},
// character: '�'
  {0xda, &Arial9_b_0xda},
// character: '�'
  {0xdb, &Arial9_b_0xdb},
// character: '�'
  {0xdc, &Arial9_b_0xdc},
// character: '�'
  {0xdd, &Arial9_b_0xdd},
// character: '�'
  {0xde, &Arial9_b_0xde},
// character: '�'
  {0xdf, &Arial9_b_0xdf},
// character: '�'
  {0xe0, &Arial9_b_0xe0},
// character: '�'
  {0xe1, &Arial9_b_0xe1},
// character: '�'
  {0xe2, &Arial9_b_0xe2},
// character: '�'
  {0xe3, &Arial9_b_0xe3},
// character: '�'
  {0xe4, &Arial9_b_0xe4},
// character: '�'
  {0xe5, &Arial9_b_0xe5},
// character: '�'
  {0xe6, &Arial9_b_0xe6},
// character: '�'
  {0xe7, &Arial9_b_0xe7},
// character: '�'
  {0xe8, &Arial9_b_0xe8},
// character: '�'
  {0xe9, &Arial9_b_0xe9},
// character: '�'
  {0xea, &Arial9_b_0xea},
// character: '�'
  {0xeb, &Arial9_b_0xeb},
// character: '�'
  {0xec, &Arial9_b_0xec},
// character: '�'
  {0xed, &Arial9_b_0xed},
// character: '�'
  {0xee, &Arial9_b_0xee},
// character: '�'
  {0xef, &Arial9_b_0xef},
// character: '�'
  {0xf0, &Arial9_b_0xf0},
// character: '�'
  {0xf1, &Arial9_b_0xf1},
// character: '�'
  {0xf2, &Arial9_b_0xf2},
// character: '�'
  {0xf3, &Arial9_b_0xf3},
// character: '�'
  {0xf4, &Arial9_b_0xf4},
// character: '�'
  {0xf5, &Arial9_b_0xf5},
// character: '�'
  {0xf6, &Arial9_b_0xf6},
// character: '�'
  {0xf7, &Arial9_b_0xf7},
// character: '�'
  {0xf8, &Arial9_b_0xf8},
// character: '�'
  {0xf9, &Arial9_b_0xf9},
// character: '�'
  {0xfa, &Arial9_b_0xfa},
// character: '�'
  {0xfb, &Arial9_b_0xfb},
// character: '�'
  {0xfc, &Arial9_b_0xfc},
// character: '�'
  {0xfd, &Arial9_b_0xfd},
// character: '�'
  {0xfe, &Arial9_b_0xfe},
// character: '�'
  {0xff, &Arial9_b_0xff},
// character: '�'
  {0xaa, &Arial9_b_0xaa},
// character: '�'
  {0xb2, &Arial9_b_0xb2},
// character: '�'
  {0xaf, &Arial9_b_0xaf},
// character: '�'
  {0xba, &Arial9_b_0xba},
// character: '�'
  {0xb3, &Arial9_b_0xb3},
// character: '�'
  {0xbf, &Arial9_b_0xbf}
};

static const tFont Arial9_b = { 165, Arial9_b_array };

#endif /* ARIAL9_B_H_ */
