#ifndef MWS_INCLUDE_MWS_VERSION_H
#define MWS_INCLUDE_MWS_VERSION_H

#define MWS_VERSION_MAJOR 0
#define MWS_VERSION_MINOR 1
#define MWS_VERSION_PATCH 0

#define MWS_STR(str) MWS_STR_IMPL(str)
#define MWS_STR_IMPL(str) #str

#define MWS_VERSION MWS_STR(MWS_VERSION_MAJOR) "." MWS_STR(MWS_VERSION_MINOR) "." MWS_STR(MWS_VERSION_PATCH)

#endif // MWS_INCLUDE_MWS_VERSION_H
