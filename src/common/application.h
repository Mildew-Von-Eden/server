/*
===========================================================================

  Copyright (c) 2022 LandSandBoat Dev Teams

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/

===========================================================================
*/

#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "common/logging_service.h"
#include "common/zmq_service.h"

#include "argparse/argparse.hpp"

// TODO: CTRP Singletons for services?
// What defines a service?

class Application
{
public:
    Application(std::unique_ptr<argparse::ArgumentParser>&& pArgParser);
    virtual ~Application() = default;

    Application(const Application&) = delete;            // Copy constructor
    Application(Application&&) = delete;                 // Move constructor
    Application& operator=(const Application&) = delete; // Copy assignment operator
    Application& operator=(Application&&) = delete;      // Move assignment operator

    virtual bool IsRunning();
    virtual void Tick();

    std::unique_ptr<argparse::ArgumentParser> gArgParser;

    bool bIsRunning;

private:
    //
};
