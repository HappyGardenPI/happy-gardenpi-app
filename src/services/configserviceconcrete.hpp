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

#include <string>

#include "configservice.hpp"
#include "../interfaces/object.hpp"
#include "../constants.hpp"
#include "../pods/configinfo.hpp"

namespace hgardenpi
{
    inline namespace v1
    {

        using std::make_shared;
        using std::string;

        /**
         * @brief Class for configuration reading from json file
         * 
         */
        //TODO: Remove this
        class ConfigServiceConcrete final :  public ConfigService, public Object
        {

            const string configFile;

        public:
            /**
             * @brief Construct a new Config Serivce object
             * 
             * @param configFile path of config file in json format
             */
            inline explicit ConfigServiceConcrete(string &&configFile) noexcept : configFile(configFile)
            {
            }

            /**
             * @brief read configuration
             * 
             * @throw runtime_error if something is wrong
             */
            ConfigInfo::Ptr read() noexcept override;

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