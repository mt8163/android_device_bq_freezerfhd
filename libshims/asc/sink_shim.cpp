/* Those symbols are requested by the "sink" binary located at "/system/bin/" 
   Actually IDA didn't showed up any function regarding to those so just return 0 */

#include <inttypes.h>

extern "C"
{
    int _ZN7android10DataSource23RegisterDefaultSniffersEv()
    {
        return 0;
    }

    int _ZNK7android16NuMediaExtractor14getTrackFormatEmPNS_2spINS_8AMessageEEE(uint64_t track_name)
    {
        return 0;
    }

    int _ZN7android14FindAVCSPSInfoEPhmPNS_7SPSInfoE(uint32_t info_name)
    {
        return 0;
    }
}
