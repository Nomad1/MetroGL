//-----------------------------------------------------------------------------------------------
// Copyright (c) 2012 Andrew Garrison
//-----------------------------------------------------------------------------------------------
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
// and associated documentation files (the "Software"), to deal in the Software without 
// restriction, including without limitation the rights to use, copy, modify, merge, publish, 
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or 
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//-----------------------------------------------------------------------------------------------
#pragma once

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

// Version
#define GL_VERSION_1_1                    1

// AlphaFunction
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207

// BeginMode
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_QUAD_STRIP                     0x0008
#define GL_POLYGON                        0x0009

// BlendingFactorDest
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305

// BlendingFactorSrc
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308

// Boolean
#define GL_TRUE                           1
#define GL_FALSE                          0

// ClipPlaneName
#define GL_CLIP_PLANE0                    0x3000
#define GL_CLIP_PLANE1                    0x3001
#define GL_CLIP_PLANE2                    0x3002
#define GL_CLIP_PLANE3                    0x3003
#define GL_CLIP_PLANE4                    0x3004
#define GL_CLIP_PLANE5                    0x3005

// DataType
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_2_BYTES                        0x1407
#define GL_3_BYTES                        0x1408
#define GL_4_BYTES                        0x1409
#define GL_DOUBLE                         0x140A
// Packing type

#define GL_UNSIGNED_SHORT_5_6_5			0x8363
#define GL_UNSIGNED_SHORT_4_4_4_4		0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1		0x8034

// GetTarget
#define GL_COLOR_MATERIAL                 0x0B57
#define GL_BLEND                          0x0BE2
#define GL_SCISSOR_TEST                   0x0C11
#define GL_TEXTURE_2D                     0x0DE1

#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_TEXTURE_BORDER                 0x1005
#define GL_TEXTURE_BINDING_2D             0x8069

// MatrixMode
#define GL_MODELVIEW                      0x1700
#define GL_PROJECTION                     0x1701
#define GL_TEXTURE                        0x1702

// PixelFormat
#define GL_COLOR_INDEX                    0x1900
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_LUMINANCE                      0x1909
#define GL_LUMINANCE_ALPHA                0x190A

// PixelType
#define GL_BITMAP                         0x1A00

// PolygonMode
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02

// TextureCoordName
#define GL_S                              0x2000
#define GL_T                              0x2001
#define GL_R                              0x2002
#define GL_Q                              0x2003

// TextureEnvMode
#define GL_MODULATE                       0x2100
#define GL_DECAL                          0x2101

// TextureEnvParameter
#define GL_TEXTURE_ENV_MODE               0x2200
#define GL_TEXTURE_ENV_COLOR              0x2201

// TextureEnvTarget
#define GL_TEXTURE_ENV                    0x2300

// TextureGenMode
#define GL_EYE_LINEAR                     0x2400
#define GL_OBJECT_LINEAR                  0x2401
#define GL_SPHERE_MAP                     0x2402

// TextureGenParameter
#define GL_TEXTURE_GEN_MODE               0x2500
#define GL_OBJECT_PLANE                   0x2501
#define GL_EYE_PLANE                      0x2502

// TextureMagFilter
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601

// TextureMinFilter
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703

// TextureParameterName
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803

// TextureWrapMode
#define GL_CLAMP                          0x2900
#define GL_REPEAT                         0x2901

// vertex_array
#define GL_VERTEX_ARRAY                   0x8074
#define GL_COLOR_ARRAY                    0x8076
#define GL_INDEX_ARRAY                    0x8077
#define GL_TEXTURE_COORD_ARRAY            0x8078

//************************************************************/

//void glAccum (GLenum op, GLfloat value);
//void glAlphaFunc (GLenum func, GLclampf ref);
//GLboolean glAreTexturesResident (GLsizei n, const GLuint *textures, GLboolean *residences);
//void glArrayElement (GLint i);
//void glBegin (GLenum mode);
void glBindTexture (GLenum target, GLuint texture);
//void glBitmap (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
void glBlendFunc (GLenum sfactor, GLenum dfactor);
//void glCallList (GLuint list);
//void glCallLists (GLsizei n, GLenum type, const GLvoid *lists);
//void glClear (GLbitfield mask);
//void glClearAccum (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
//void glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
//void glClearDepth (GLclampd depth);
//void glClearIndex (GLfloat c);
//void glClearStencil (GLint s);
//void glClipPlane (GLenum plane, const GLdouble *equation);
//void glColor3b (GLbyte red, GLbyte green, GLbyte blue);
//void glColor3bv (const GLbyte *v);
//void glColor3d (GLdouble red, GLdouble green, GLdouble blue);
//void glColor3dv (const GLdouble *v);
//void glColor3f (GLfloat red, GLfloat green, GLfloat blue);
//void glColor3fv (const GLfloat *v);
//void glColor3i (GLint red, GLint green, GLint blue);
//void glColor3iv (const GLint *v);
//void glColor3s (GLshort red, GLshort green, GLshort blue);
//void glColor3sv (const GLshort *v);
//void glColor3ub (GLubyte red, GLubyte green, GLubyte blue);
//void glColor3ubv (const GLubyte *v);
//void glColor3ui (GLuint red, GLuint green, GLuint blue);
//void glColor3uiv (const GLuint *v);
//void glColor3us (GLushort red, GLushort green, GLushort blue);
//void glColor3usv (const GLushort *v);
//void glColor4b (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
//void glColor4bv (const GLbyte *v);
//void glColor4d (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
//void glColor4dv (const GLdouble *v);
//void glColor4f (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
//void glColor4fv (const GLfloat *v);
//void glColor4i (GLint red, GLint green, GLint blue, GLint alpha);
//void glColor4iv (const GLint *v);
//void glColor4s (GLshort red, GLshort green, GLshort blue, GLshort alpha);
//void glColor4sv (const GLshort *v);
void glColor4ub (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
//void glColor4ubv (const GLubyte *v);
//void glColor4ui (GLuint red, GLuint green, GLuint blue, GLuint alpha);
//void glColor4uiv (const GLuint *v);
//void glColor4us (GLushort red, GLushort green, GLushort blue, GLushort alpha);
//void glColor4usv (const GLushort *v);
//void glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
//void glColorMaterial (GLenum face, GLenum mode);
void glColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
//void glCopyPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
//void glCopyTexImage1D (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
//void glCopyTexImage2D (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
//void glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
//void glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
//void glCullFace (GLenum mode);
//void glDeleteLists (GLuint list, GLsizei range);
void glDeleteTextures (GLsizei n, const GLuint *textures);
//void glDepthFunc (GLenum func);
//void glDepthMask (GLboolean flag);
//void glDepthRange (GLclampd zNear, GLclampd zFar);
void glDisable (GLenum cap);
void glDisableClientState (GLenum array);
void glDrawArrays (GLenum mode, GLint first, GLsizei count);
//void glDrawBuffer (GLenum mode);
void glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
//void glDrawPixels (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
//void glEdgeFlag (GLboolean flag);
//void glEdgeFlagPointer (GLsizei stride, const GLvoid *pointer);
//void glEdgeFlagv (const GLboolean *flag);
void glEnable (GLenum cap);
void glEnableClientState (GLenum array);
//void glEnd (void);
//void glEndList (void);
//void glEvalCoord1d (GLdouble u);
//void glEvalCoord1dv (const GLdouble *u);
//void glEvalCoord1f (GLfloat u);
//void glEvalCoord1fv (const GLfloat *u);
//void glEvalCoord2d (GLdouble u, GLdouble v);
//void glEvalCoord2dv (const GLdouble *u);
//void glEvalCoord2f (GLfloat u, GLfloat v);
//void glEvalCoord2fv (const GLfloat *u);
//void glEvalMesh1 (GLenum mode, GLint i1, GLint i2);
//void glEvalMesh2 (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
//void glEvalPoint1 (GLint i);
//void glEvalPoint2 (GLint i, GLint j);
//void glFeedbackBuffer (GLsizei size, GLenum type, GLfloat *buffer);
//void glFinish (void);
//void glFlush (void);
//void glFogf (GLenum pname, GLfloat param);
//void glFogfv (GLenum pname, const GLfloat *params);
//void glFogi (GLenum pname, GLint param);
//void glFogiv (GLenum pname, const GLint *params);
//void glFrontFace (GLenum mode);
//void glFrustum (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
//GLuint glGenLists (GLsizei range);
void glGenTextures (GLsizei n, GLuint *textures);
//void glGetBooleanv (GLenum pname, GLboolean *params);
//void glGetClipPlane (GLenum plane, GLdouble *equation);
//void glGetDoublev (GLenum pname, GLdouble *params);
//GLenum glGetError (void);
//void glGetFloatv (GLenum pname, GLfloat *params);
void glGetIntegerv (GLenum pname, GLint *params);
//void glGetLightfv (GLenum light, GLenum pname, GLfloat *params);
//void glGetLightiv (GLenum light, GLenum pname, GLint *params);
//void glGetMapdv (GLenum target, GLenum query, GLdouble *v);
//void glGetMapfv (GLenum target, GLenum query, GLfloat *v);
//void glGetMapiv (GLenum target, GLenum query, GLint *v);
//void glGetMaterialfv (GLenum face, GLenum pname, GLfloat *params);
//void glGetMaterialiv (GLenum face, GLenum pname, GLint *params);
//void glGetPixelMapfv (GLenum map, GLfloat *values);
//void glGetPixelMapuiv (GLenum map, GLuint *values);
//void glGetPixelMapusv (GLenum map, GLushort *values);
//void glGetPointerv (GLenum pname, GLvoid* *params);
//void glGetPolygonStipple (GLubyte *mask);
//const GLubyte * glGetString (GLenum name);
//void glGetTexEnvfv (GLenum target, GLenum pname, GLfloat *params);
//void glGetTexEnviv (GLenum target, GLenum pname, GLint *params);
//void glGetTexGendv (GLenum coord, GLenum pname, GLdouble *params);
//void glGetTexGenfv (GLenum coord, GLenum pname, GLfloat *params);
//void glGetTexGeniv (GLenum coord, GLenum pname, GLint *params);
//void glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
//void glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
//void glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
//void glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
//void glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
//void glHint (GLenum target, GLenum mode);
//void glIndexMask (GLuint mask);
//void glIndexPointer (GLenum type, GLsizei stride, const GLvoid *pointer);
//void glIndexd (GLdouble c);
//void glIndexdv (const GLdouble *c);
//void glIndexf (GLfloat c);
//void glIndexfv (const GLfloat *c);
//void glIndexi (GLint c);
//void glIndexiv (const GLint *c);
//void glIndexs (GLshort c);
//void glIndexsv (const GLshort *c);
//void glIndexub (GLubyte c);
//void glIndexubv (const GLubyte *c);
//void glInitNames (void);
//void glInterleavedArrays (GLenum format, GLsizei stride, const GLvoid *pointer);
//GLboolean glIsEnabled (GLenum cap);
//GLboolean glIsList (GLuint list);
//GLboolean glIsTexture (GLuint texture);
//void glLightModelf (GLenum pname, GLfloat param);
//void glLightModelfv (GLenum pname, const GLfloat *params);
//void glLightModeli (GLenum pname, GLint param);
//void glLightModeliv (GLenum pname, const GLint *params);
//void glLightf (GLenum light, GLenum pname, GLfloat param);
//void glLightfv (GLenum light, GLenum pname, const GLfloat *params);
//void glLighti (GLenum light, GLenum pname, GLint param);
//void glLightiv (GLenum light, GLenum pname, const GLint *params);
//void glLineStipple (GLint factor, GLushort pattern);
void glLineWidth (GLfloat width);
//void glListBase (GLuint base);
void glLoadIdentity (void);
//void glLoadMatrixd (const GLdouble *m);
void glLoadMatrixf (const GLfloat *m);
//void glLoadName (GLuint name);
//void glLogicOp (GLenum opcode);
//void glMap1d (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
//void glMap1f (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
//void glMap2d (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
//void glMap2f (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
//void glMapGrid1d (GLint un, GLdouble u1, GLdouble u2);
//void glMapGrid1f (GLint un, GLfloat u1, GLfloat u2);
//void glMapGrid2d (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
//void glMapGrid2f (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
//void glMaterialf (GLenum face, GLenum pname, GLfloat param);
//void glMaterialfv (GLenum face, GLenum pname, const GLfloat *params);
//void glMateriali (GLenum face, GLenum pname, GLint param);
//void glMaterialiv (GLenum face, GLenum pname, const GLint *params);
void glMatrixMode (GLenum mode);
//void glMultMatrixd (const GLdouble *m);
//void glMultMatrixf (const GLfloat *m);
//void glNewList (GLuint list, GLenum mode);
//void glNormal3b (GLbyte nx, GLbyte ny, GLbyte nz);
//void glNormal3bv (const GLbyte *v);
//void glNormal3d (GLdouble nx, GLdouble ny, GLdouble nz);
//void glNormal3dv (const GLdouble *v);
//void glNormal3f (GLfloat nx, GLfloat ny, GLfloat nz);
//void glNormal3fv (const GLfloat *v);
//void glNormal3i (GLint nx, GLint ny, GLint nz);
//void glNormal3iv (const GLint *v);
//void glNormal3s (GLshort nx, GLshort ny, GLshort nz);
//void glNormal3sv (const GLshort *v);
//void glNormalPointer (GLenum type, GLsizei stride, const GLvoid *pointer);
void glOrtho (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
//void glPassThrough (GLfloat token);
//void glPixelMapfv (GLenum map, GLsizei mapsize, const GLfloat *values);
//void glPixelMapuiv (GLenum map, GLsizei mapsize, const GLuint *values);
//void glPixelMapusv (GLenum map, GLsizei mapsize, const GLushort *values);
//void glPixelStoref (GLenum pname, GLfloat param);
//void glPixelStorei (GLenum pname, GLint param);
//void glPixelTransferf (GLenum pname, GLfloat param);
//void glPixelTransferi (GLenum pname, GLint param);
//void glPixelZoom (GLfloat xfactor, GLfloat yfactor);
//void glPointSize (GLfloat size);
//void glPolygonMode (GLenum face, GLenum mode);
//void glPolygonOffset (GLfloat factor, GLfloat units);
//void glPolygonStipple (const GLubyte *mask);
//void glPopAttrib (void);
//void glPopClientAttrib (void);
void glPopMatrix (void);
//void glPopName (void);
//void glPrioritizeTextures (GLsizei n, const GLuint *textures, const GLclampf *priorities);
//void glPushAttrib (GLbitfield mask);
//void glPushClientAttrib (GLbitfield mask);
void glPushMatrix (void);
//void glPushName (GLuint name);
//void glRasterPos2d (GLdouble x, GLdouble y);
//void glRasterPos2dv (const GLdouble *v);
//void glRasterPos2f (GLfloat x, GLfloat y);
//void glRasterPos2fv (const GLfloat *v);
//void glRasterPos2i (GLint x, GLint y);
//void glRasterPos2iv (const GLint *v);
//void glRasterPos2s (GLshort x, GLshort y);
//void glRasterPos2sv (const GLshort *v);
//void glRasterPos3d (GLdouble x, GLdouble y, GLdouble z);
//void glRasterPos3dv (const GLdouble *v);
//void glRasterPos3f (GLfloat x, GLfloat y, GLfloat z);
//void glRasterPos3fv (const GLfloat *v);
//void glRasterPos3i (GLint x, GLint y, GLint z);
//void glRasterPos3iv (const GLint *v);
//void glRasterPos3s (GLshort x, GLshort y, GLshort z);
//void glRasterPos3sv (const GLshort *v);
//void glRasterPos4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
//void glRasterPos4dv (const GLdouble *v);
//void glRasterPos4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
//void glRasterPos4fv (const GLfloat *v);
//void glRasterPos4i (GLint x, GLint y, GLint z, GLint w);
//void glRasterPos4iv (const GLint *v);
//void glRasterPos4s (GLshort x, GLshort y, GLshort z, GLshort w);
//void glRasterPos4sv (const GLshort *v);
//void glReadBuffer (GLenum mode);
//void glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
//void glRectd (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
//void glRectdv (const GLdouble *v1, const GLdouble *v2);
//void glRectf (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
//void glRectfv (const GLfloat *v1, const GLfloat *v2);
//void glRecti (GLint x1, GLint y1, GLint x2, GLint y2);
//void glRectiv (const GLint *v1, const GLint *v2);
//void glRects (GLshort x1, GLshort y1, GLshort x2, GLshort y2);
//void glRectsv (const GLshort *v1, const GLshort *v2);
//GLint glRenderMode (GLenum mode);
//void glRotated (GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
//void glScaled (GLdouble x, GLdouble y, GLdouble z);
void glScalef (GLfloat x, GLfloat y, GLfloat z);
void glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
//void glSelectBuffer (GLsizei size, GLuint *buffer);
//void glShadeModel (GLenum mode);
//void glStencilFunc (GLenum func, GLint ref, GLuint mask);
//void glStencilMask (GLuint mask);
//void glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
//void glTexCoord1d (GLdouble s);
//void glTexCoord1dv (const GLdouble *v);
//void glTexCoord1f (GLfloat s);
//void glTexCoord1fv (const GLfloat *v);
//void glTexCoord1i (GLint s);
//void glTexCoord1iv (const GLint *v);
//void glTexCoord1s (GLshort s);
//void glTexCoord1sv (const GLshort *v);
//void glTexCoord2d (GLdouble s, GLdouble t);
//void glTexCoord2dv (const GLdouble *v);
//void glTexCoord2f (GLfloat s, GLfloat t);
//void glTexCoord2fv (const GLfloat *v);
//void glTexCoord2i (GLint s, GLint t);
//void glTexCoord2iv (const GLint *v);
//void glTexCoord2s (GLshort s, GLshort t);
//void glTexCoord2sv (const GLshort *v);
//void glTexCoord3d (GLdouble s, GLdouble t, GLdouble r);
//void glTexCoord3dv (const GLdouble *v);
//void glTexCoord3f (GLfloat s, GLfloat t, GLfloat r);
//void glTexCoord3fv (const GLfloat *v);
//void glTexCoord3i (GLint s, GLint t, GLint r);
//void glTexCoord3iv (const GLint *v);
//void glTexCoord3s (GLshort s, GLshort t, GLshort r);
//void glTexCoord3sv (const GLshort *v);
//void glTexCoord4d (GLdouble s, GLdouble t, GLdouble r, GLdouble q);
//void glTexCoord4dv (const GLdouble *v);
//void glTexCoord4f (GLfloat s, GLfloat t, GLfloat r, GLfloat q);
//void glTexCoord4fv (const GLfloat *v);
//void glTexCoord4i (GLint s, GLint t, GLint r, GLint q);
//void glTexCoord4iv (const GLint *v);
//void glTexCoord4s (GLshort s, GLshort t, GLshort r, GLshort q);
//void glTexCoord4sv (const GLshort *v);
void glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glTexEnvf (GLenum target, GLenum pname, GLfloat param);
//void glTexEnvfv (GLenum target, GLenum pname, const GLfloat *params);
void glTexEnvi (GLenum target, GLenum pname, GLint param);
//void glTexEnviv (GLenum target, GLenum pname, const GLint *params);
//void glTexGend (GLenum coord, GLenum pname, GLdouble param);
//void glTexGendv (GLenum coord, GLenum pname, const GLdouble *params);
//void glTexGenf (GLenum coord, GLenum pname, GLfloat param);
//void glTexGenfv (GLenum coord, GLenum pname, const GLfloat *params);
//void glTexGeni (GLenum coord, GLenum pname, GLint param);
//void glTexGeniv (GLenum coord, GLenum pname, const GLint *params);
//void glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glTexParameterf (GLenum target, GLenum pname, GLfloat param);
//void glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
void glTexParameteri (GLenum target, GLenum pname, GLint param);
//void glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
//void glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
//void glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
//void glTranslated (GLdouble x, GLdouble y, GLdouble z);
void glTranslatef (GLfloat x, GLfloat y, GLfloat z);
//void glVertex2d (GLdouble x, GLdouble y);
//void glVertex2dv (const GLdouble *v);
//void glVertex2f (GLfloat x, GLfloat y);
//void glVertex2fv (const GLfloat *v);
//void glVertex2i (GLint x, GLint y);
//void glVertex2iv (const GLint *v);
//void glVertex2s (GLshort x, GLshort y);
//void glVertex2sv (const GLshort *v);
//void glVertex3d (GLdouble x, GLdouble y, GLdouble z);
//void glVertex3dv (const GLdouble *v);
//void glVertex3f (GLfloat x, GLfloat y, GLfloat z);
//void glVertex3fv (const GLfloat *v);
//void glVertex3i (GLint x, GLint y, GLint z);
//void glVertex3iv (const GLint *v);
//void glVertex3s (GLshort x, GLshort y, GLshort z);
//void glVertex3sv (const GLshort *v);
//void glVertex4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
//void glVertex4dv (const GLdouble *v);
//void glVertex4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
//void glVertex4fv (const GLfloat *v);
//void glVertex4i (GLint x, GLint y, GLint z, GLint w);
//void glVertex4iv (const GLint *v);
//void glVertex4s (GLshort x, GLshort y, GLshort z, GLshort w);
//void glVertex4sv (const GLshort *v);
void glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
