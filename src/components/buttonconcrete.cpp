// MIT License
//
// Copyright (c) $year. Happy GardenPI
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
//

//
// Created by Antonio Salsi on 29/07/21.
//

#include "buttonconcrete.hpp"

#include <wiringPi.h>

#include <stdexcept>

using namespace std;


using hgardenpi::v1::ButtonConcrete;

static int lcdRS;
static ButtonConcrete::OnClick callback;
static ButtonConcrete::OnClick internalCallback;


ButtonConcrete::ButtonConcrete(int lcdRS) noexcept
{
    pinMode(lcdRS, INPUT);
    ::callback = []{};
    ::internalCallback = []{};
    ::lcdRS = lcdRS;
}

void ButtonConcrete::setOnClick(OnClick onClick) const noexcept
{
    ::callback = move(onClick);
}

void ButtonConcrete::setInternalOnClick(OnClick onClick) const
{
    ::internalCallback = move(onClick);

    //set timeout for interrupt
    if (waitForInterrupt(::lcdRS, static_cast<int>(Time::TICK)) == -1)
    {
        throw runtime_error("waitForInterrupt not run, the hw is not ready");
    }

    //set callback on click button
    if (wiringPiISR(::lcdRS, INT_EDGE_RISING, []
    {
        ::callback();
        ::internalCallback();
    }) == -1)
    {
        throw runtime_error("wiringPiISR not run, the hw is not ready");
    }
}
