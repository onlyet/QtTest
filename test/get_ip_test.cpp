#if 0

#include "common.h"

#if 0
#include <Windows.h>
#include <Iphlpapi.h>

void get_ip_list(QMap<QString, int>& map_ip)
{
    DWORD dwRetVal = 0;
    PIP_ADAPTER_INFO pAdapterInfo = (IP_ADAPTER_INFO*)malloc(sizeof(IP_ADAPTER_INFO));
    ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);

    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) != ERROR_SUCCESS)
    {
        GlobalFree(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO*)malloc(ulOutBufLen);
    }

    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR)
    {
        while (pAdapterInfo)
        {
            if (strstr(pAdapterInfo->Description, "PCI") > 0
                || (IF_TYPE_IEEE80211 == pAdapterInfo->Type && 0 < strstr(pAdapterInfo->Description, "802")))
            {
                PIP_ADDR_STRING addr = &(pAdapterInfo->IpAddressList);
                do
                {
                    if (IF_TYPE_IEEE80211 == pAdapterInfo->Type)
                        map_ip.insert(addr->IpAddress.String, 0);
                    else
                        map_ip.insert(addr->IpAddress.String, 1);
                    addr = addr->Next;
                } while (addr);
            }
            pAdapterInfo = pAdapterInfo->Next;
        }
    }
    else
    {
        qDebug() << "GetAdaptersInfo failed with error: " << dwRetVal;
    }

    if (pAdapterInfo)
    {
        GlobalFree(pAdapterInfo);
    }
}

void getIPTest()
{
    QMap<QString, int> ipv4;

    get_ip_list(ipv4);

    QMapIterator<QString, int> it(ipv4);
    while (it.hasNext())
    {
        it.next();
        qDebug() << it.key() << " : " << it.value();
    }
}
#endif

// 该方法只能获取到IPV4

#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

#include <QString>

#pragma comment(lib, "IPHLPAPI.lib")

//#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
//#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int __cdecl main()
{

    /* Declare and initialize variables */

// It is possible for an adapter to have multiple
// IPv4 addresses, gateways, and secondary WINS servers
// assigned to the adapter. 
//
// Note that this sample code only prints out the 
// first entry for the IP address/mask, and gateway, and
// the primary and secondary WINS server for each adapter. 

    PIP_ADAPTER_INFO pAdapterInfo;
    PIP_ADAPTER_INFO pAdapter = NULL;
    DWORD dwRetVal = 0;
    UINT i;

    /* variables used to print DHCP time info */
    //struct tm newtime;
    //char buffer[32];
    //errno_t error;

    ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
    pAdapterInfo = (IP_ADAPTER_INFO*)malloc(sizeof(IP_ADAPTER_INFO));
    if (pAdapterInfo == NULL) {
        printf("Error allocating memory needed to call GetAdaptersinfo\n");
        return 1;
    }
    // Make an initial call to GetAdaptersInfo to get
    // the necessary size into the ulOutBufLen variable
    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
        free(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO*)malloc(ulOutBufLen);
        if (pAdapterInfo == NULL) {
            printf("Error allocating memory needed to call GetAdaptersinfo\n");
            return 1;
        }
    }

    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR) {
        pAdapter = pAdapterInfo;
        while (pAdapter) {
            QString desc(pAdapter->Description);
            if (desc.contains("VMnet1") || desc.contains("VMnet8") 
                || desc.contains("Hyper-V")
                || desc.contains("Microsoft Wi-Fi Direct Virtual Adapter")
                ) {
                pAdapter = pAdapter->Next;
                continue;
            }
            //printf("\tComboIndex: \t%d\n", pAdapter->ComboIndex);
            //printf("\tAdapter Name: \t%s\n", pAdapter->AdapterName);
            printf("\tAdapter Desc: \t%s\n", pAdapter->Description);

            //printf("\tAdapter Addr: \t");
            //for (i = 0; i < pAdapter->AddressLength; i++) {
            //    if (i == (pAdapter->AddressLength - 1))
            //        printf("%.2X\n", (int)pAdapter->Address[i]);
            //    else
            //        printf("%.2X-", (int)pAdapter->Address[i]);
            //}
            //printf("\tIndex: \t%d\n", pAdapter->Index);
            //printf("\tType: \t");
            //switch (pAdapter->Type) {
            //case MIB_IF_TYPE_OTHER:
            //    printf("Other\n");
            //    break;
            //case MIB_IF_TYPE_ETHERNET:
            //    printf("Ethernet\n");
            //    break;
            //case MIB_IF_TYPE_TOKENRING:
            //    printf("Token Ring\n");
            //    break;
            //case MIB_IF_TYPE_FDDI:
            //    printf("FDDI\n");
            //    break;
            //case MIB_IF_TYPE_PPP:
            //    printf("PPP\n");
            //    break;
            //case MIB_IF_TYPE_LOOPBACK:
            //    printf("Lookback\n");
            //    break;
            //case MIB_IF_TYPE_SLIP:
            //    printf("Slip\n");
            //    break;
            //default:
            //    printf("Unknown type %ld\n", pAdapter->Type);
            //    break;
            //}

            //printf("\tIP Address: \t%s\n",
            //    pAdapter->IpAddressList.IpAddress.String);

            IP_ADDR_STRING* pAddr = &pAdapter->IpAddressList;
            while (pAddr) {
                QString IP(pAddr->IpAddress.String);
                if (IP.contains("0.0.0.0")) {
                    //
                }
                printf("\tIP Address: \t%s\n",
                    pAddr->IpAddress.String);
                pAddr = pAddr->Next;
            }

            //printf("\tIP Mask: \t%s\n", pAdapter->IpAddressList.IpMask.String);

            //printf("\tGateway: \t%s\n", pAdapter->GatewayList.IpAddress.String);
            //printf("\t***\n");

            //if (pAdapter->DhcpEnabled) {
            //    printf("\tDHCP Enabled: Yes\n");
            //    printf("\t  DHCP Server: \t%s\n",
            //        pAdapter->DhcpServer.IpAddress.String);

            //    printf("\t  Lease Obtained: ");
            //    /* Display local time */
            //    error = _localtime32_s(&newtime, (__time32_t*)&pAdapter->LeaseObtained);
            //    if (error)
            //        printf("Invalid Argument to _localtime32_s\n");
            //    else {
            //        // Convert to an ASCII representation 
            //        error = asctime_s(buffer, 32, &newtime);
            //        if (error)
            //            printf("Invalid Argument to asctime_s\n");
            //        else
            //            /* asctime_s returns the string terminated by \n\0 */
            //            printf("%s", buffer);
            //    }

            //    printf("\t  Lease Expires:  ");
            //    error = _localtime32_s(&newtime, (__time32_t*)&pAdapter->LeaseExpires);
            //    if (error)
            //        printf("Invalid Argument to _localtime32_s\n");
            //    else {
            //        // Convert to an ASCII representation 
            //        error = asctime_s(buffer, 32, &newtime);
            //        if (error)
            //            printf("Invalid Argument to asctime_s\n");
            //        else
            //            /* asctime_s returns the string terminated by \n\0 */
            //            printf("%s", buffer);
            //    }
            //}
            //else
            //    printf("\tDHCP Enabled: No\n");

            //if (pAdapter->HaveWins) {
            //    printf("\tHave Wins: Yes\n");
            //    printf("\t  Primary Wins Server:    %s\n",
            //        pAdapter->PrimaryWinsServer.IpAddress.String);
            //    printf("\t  Secondary Wins Server:  %s\n",
            //        pAdapter->SecondaryWinsServer.IpAddress.String);
            //}
            //else
            //    printf("\tHave Wins: No\n");
            pAdapter = pAdapter->Next;
            printf("\n");
        }
    }
    else {
        printf("GetAdaptersInfo failed with error: %d\n", dwRetVal);

    }
    if (pAdapterInfo)
        free(pAdapterInfo);

    return 0;
}
#endif