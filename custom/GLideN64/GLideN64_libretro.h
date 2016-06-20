#ifndef GLIDEN64_LIBRETRO_H
#define GLIDEN64_LIBRETRO_H

#ifdef GLES2
#define GL_DRAW_FRAMEBUFFER GL_FRAMEBUFFER
#define GL_READ_FRAMEBUFFER GL_FRAMEBUFFER
#define GLESX
#ifdef PANDORA
typedef char GLchar;
#endif
#elif defined(GLES3)
#define GLESX
#define GL_UNIFORMBLOCK_SUPPORT
#elif defined(GLES3_1)
#define GLESX
#define GL_IMAGE_TEXTURES_SUPPORT
#define GL_MULTISAMPLING_SUPPORT
#define GL_UNIFORMBLOCK_SUPPORT
#elif defined(EGL)
#define GL_IMAGE_TEXTURES_SUPPORT
#define GL_MULTISAMPLING_SUPPORT
#define GL_UNIFORMBLOCK_SUPPORT
#else
#if defined(OS_MAC_OS_X)
#define GL_GLEXT_PROTOTYPES
#elif defined(OS_LINUX)
#define GL_GLEXT_PROTOTYPES
#define GL_IMAGE_TEXTURES_SUPPORT
#define GL_MULTISAMPLING_SUPPORT
#define GL_UNIFORMBLOCK_SUPPORT
#elif defined(OS_WINDOWS)
#define GL_IMAGE_TEXTURES_SUPPORT
#define GL_MULTISAMPLING_SUPPORT
#define GL_UNIFORMBLOCK_SUPPORT
#endif // OS_MAC_OS_X
#endif // GLES2

struct GLState {
	GLState() { reset(); }
	void reset();
};

extern GLState glState;

#endif
