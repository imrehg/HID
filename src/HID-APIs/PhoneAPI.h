/*
Copyright (c) 2014-2015 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// Include guard
#pragma once

#include <Arduino.h>
#include "HID-Settings.h"

enum PhoneKeycode : uint16_t {
	HID_PHONE_UNASSIGNED = 0x00,

	// Telephony_Page_(0x0B)
	HID_PHONE_HOOK_SWITCH = 0x20, // HID type OOC
	HID_PHONE_MUTE = 0x2F, // HID type OOC

};

typedef union ATTRIBUTE_PACKED {
	// Every usable system control key possible
	uint8_t whole8[0];
	uint8_t key;
} HID_PhoneControlReport_Data_t;

class PhoneAPI{
public:
	inline PhoneAPI(void);
	inline void begin(void);
	inline void end(void);
	inline void write(PhoneKeycode p);
	inline void press(PhoneKeycode p);
	inline void release(void);
	inline void releaseAll(void);

	// Sending is public in the base class for advanced users.
	virtual void SendReport(void* data, int length) = 0;
};

// Implementation is inline
#include "PhoneAPI.hpp"
