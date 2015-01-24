#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct scaleform_file_download_complete
{
   bool success;
   std::string local_filename;
   std::string remote_url;
};

}

DeclareGameEvent(scaleform_file_download_complete);

}
