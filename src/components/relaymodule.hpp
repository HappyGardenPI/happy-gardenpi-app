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
// Created by Antonio Salsi on 14/08/21.
//


#pragma once

#include "../interfaces/object.hpp"
#include "../pods/station.hpp"

namespace hgardenpi
{
    inline namespace v1
    {
        /**
         * @brief Abstract relay module
         */
        class RelayModule : public Object
        {
        public:
            RelayModule() = default;
            virtual ~RelayModule() = default;

            //remove copy constructor
            HGARDENPI_NO_COPY_NO_MOVE(RelayModule)

            /**
             * @brief Set status relay
             * @param ptr Status pointer for select the right relay
             * @param status 1 close, 0 open
             * @throw runtime_error when pin is wrong
             */
            virtual void setRelay(const Station::Ptr &ptr, bool status) const = 0;
        };
    }
}
