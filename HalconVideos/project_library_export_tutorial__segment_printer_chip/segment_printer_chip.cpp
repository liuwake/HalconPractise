// segment_printer_chip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "HalconCpp.h"
#include "hdevelop/hdev_segment_printer_chip/source/hdev_segment_printer_chip.h"



int main()
{
	HalconCpp::HImage Image("printer_chip/printer_chip_01");
	HalconCpp::HRegion Region;

	hdev_segment_printer_chip::SetResourcePath("./hdevelop");
	hdev_segment_printer_chip::get_printer_chip_regions(Image, &Region, 128);
}