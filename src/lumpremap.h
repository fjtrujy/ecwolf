/*
** lumpremap.h
**
**---------------------------------------------------------------------------
** Copyright 2011 Braden Obrzut
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
**
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**---------------------------------------------------------------------------
**
**
*/

#ifndef __LUMPREMAP_H__
#define __LUMPREMAP_H__

#include "resourcefiles/resourcefile.h"
#include "tarray.h"
#include "zstring.h"

class LumpRemaper
{
	public:
		enum Type
		{
			AUDIOT,
			VGAGRAPH,
			VSWAP
		};

		LumpRemaper(const char* extension);

		void		AddFile(FResourceFile *file, Type type);
		void		DoRemap();

		static void			AddFile(const char* extension, FResourceFile *file, Type type);
		// For Read This screens which reference VGAGraph entries by number.
		static const char*	ConvertMusicIndexToLump(int num) { return musicReverseMap[num]; }
		static const char*	ConvertVGAIndexToLump(int num) { return vgaReverseMap[num]; }
		static void			RemapAll();
	protected:
		bool		LoadMap();
	private:
		struct RemapFile
		{
			FResourceFile	*file;
			Type			type;
		};

		FString				mapLumpName;
		TArray<FName>		graphics, sprites, sounds, digitalsounds, music, textures;
		TArray<RemapFile>	files;

		static TMap<FName, LumpRemaper>	remaps;
		static TMap<int, FName>			musicReverseMap;
		static TMap<int, FName>			vgaReverseMap;
};

#endif