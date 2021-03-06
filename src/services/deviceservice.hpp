// MIT License
//
// Copyright (c) 2021 Happy GardenPI
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "../pods/deviceinfo.hpp"

namespace hgardenpi
{
    inline namespace v1
    {


        /**
         * @brief Get CPU temperature
         * @exception throw exception when temp is not available
         * @return return degrees temperature
         */
        [[maybe_unused]] float getCPUTemperature();

        /**
         * @brief Get Raspberry PI info
         * @exception throw exception when temp is not available
         * @return return Raspberry PI info
         */
        [[maybe_unused]] DeviceInfo::Ptr getDeviceInfo();

        /**
         * @brief Get Raspberry wlan0 IP
         * @return actual ip address of wlan0 interface
         */
        [[maybe_unused]] string getWlan0IP();

        /**
         * @brief Get Raspberry MAC ADDRESS IP
         * @return actual MAC ADDRESS address of wlan0 interface
         */
        [[maybe_unused]] string getWlan0MAC();
    }
}