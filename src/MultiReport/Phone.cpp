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

#include "Phone.h"

static const uint8_t _hidMultiReportDescriptorPhone[] PROGMEM = {
	0x05, 0x0b,	// USAGE_PAGE (Telephony Devices)
	0x09, 0x05,	// USAGE (Headset)
	0xa1, 0x01,	// COLLECTION (Application)
	0x85, HID_REPORTID_PHONE,	//   REPORT_ID (1)
		0x25, 0x01,	//   LOGICAL_MAXIMUM (1)
		0x15, 0x00,	//   LOGICAL_MINIMUM (0)
		0x09, 0x2f,	//   USAGE (Phone Mute)
		0x75, 0x01,	//   REPORT_SIZE (1)
		0x95, 0x01,	//   REPORT_COUNT (1)
		0x81, 0x02,	//   INPUT (Data,Var,Abs)
		0x95, 0x07,	//   REPORT_COUNT (7)
		0x81, 0x03,	//   INPUT (Cnst,Var,Abs)
	0xc0		// END_COLLECTION
};

Phone_::Phone_(void) 
{
	static HIDSubDescriptor node(_hidMultiReportDescriptorPhone, sizeof(_hidMultiReportDescriptorPhone));
	HID().AppendDescriptor(&node);
}


void Phone_::SendReport(void* data, int length)
{
	HID().SendReport(HID_REPORTID_PHONE, data, length);
}

Phone_ Phone;
