using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace Hacktoberfest
{
    public static class ProcessStatus
    {
        [DllImport("psapi.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool GetPerformanceInfo([Out] out PsApiPerformanceInformation PerformanceInformation, [In] int Size);

        [StructLayout(LayoutKind.Sequential)]
        public struct PsApiPerformanceInformation
        {
            public int Size;
            public IntPtr CommitTotal;
            public IntPtr CommitLimit;
            public IntPtr CommitPeak;
            public IntPtr PhysicalTotal;
            public IntPtr PhysicalAvailable;
            public IntPtr SystemCache;
            public IntPtr KernelTotal;
            public IntPtr KernelPaged;
            public IntPtr KernelNonPaged;
            public IntPtr PageSize;
            public int HandlesCount;
            public int ProcessCount;
            public int ThreadCount;
        }

        private static PerformanceCounter CpuCounter = new PerformanceCounter("Processor", "% Processor Time", "_Total");

        public static int GetCpuUsagePercent()
        {
            return Convert.ToInt32(CpuCounter.NextValue());
        }
        
        public static long GetMemoryUsageInBytes()
        {
            long MemoryUsage = 0;
            PsApiPerformanceInformation PerfInfo = new PsApiPerformanceInformation();
            if (GetPerformanceInfo(out PerfInfo, Marshal.SizeOf(PerfInfo)))
            {
                Int64 pageSize = PerfInfo.PageSize.ToInt64();
                MemoryUsage = (PerfInfo.PhysicalTotal.ToInt64() * pageSize) - (PerfInfo.PhysicalAvailable.ToInt64() * pageSize);
                return MemoryUsage;
            }
            else
                return -1;
        }
    }
}
