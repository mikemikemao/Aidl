package com.hikvision;

import android.os.IBinder;

public class HiAcs {
    static {
        System.loadLibrary("hiacs");
    }

    public native IBinder createServiceBinder();
}
