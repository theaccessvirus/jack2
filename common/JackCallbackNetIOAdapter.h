/*
Copyright (C) 2008 Grame

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
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef __JackCallbackNetIOAdapter__
#define __JackCallbackNetIOAdapter__

#include "JackNetIOAdapter.h"
#include "ringbuffer.h"

namespace Jack
{

	class JackCallbackNetIOAdapter : public JackNetIOAdapter
	{
    
		private:
        
            jack_ringbuffer_t** fCaptureRingBuffer;
            jack_ringbuffer_t** fPlaybackRingBuffer;
            
            jack_time_t fLastCallbackTime;
            jack_time_t fCurCallbackTime;
       	
            static int Process(jack_nframes_t, void* arg);
            static int BufferSize(jack_nframes_t nframes, void *arg);
            
		public:
        
			JackCallbackNetIOAdapter(jack_client_t* jack_client, 
                                JackIOAdapterInterface* audio_io, 
                                int input, 
                                int output);
			~JackCallbackNetIOAdapter();
               
	};
}

#endif