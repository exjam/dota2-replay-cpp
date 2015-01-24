#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct file_downloaded
{
   bool success;
   std::string local_filename;
   std::string remote_url;
};

}

DeclareGameEvent(file_downloaded);

}
