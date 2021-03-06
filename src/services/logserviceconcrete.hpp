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

#include <syslog.h>
#include <mutex>

#include "logservice.hpp"
#include "../interfaces/object.hpp"

namespace hgardenpi
{
    inline namespace v1
    {

        using std::mutex;
        using std::string;

        /**
         * @brief LogService permit writing log into syslog
         */
        class LogServiceConcrete final : public LogService, public Object
        {
            mutable mutex m;

        public:
            /**
             * @brief Create new instance
             */
            LogServiceConcrete() noexcept;
            inline ~LogServiceConcrete() noexcept override
            {
                closelog();
            }

            /**
             * @brief Write log on system 
             * 
             * @param level of log
             * @param msg message to write
             * @param ...
             */
            void write(uint8_t level, const char *msg, ...) const noexcept override;

            /**
             * @brief Return the name of object
             * 
             * @return std::string name of object
             */
            inline string toString() noexcept override
            {
                return typeid(*this).name();
            }
        };

    }
}