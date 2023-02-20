package com.hikvision;

import android.os.IBinder;

public class HiAcs {
    static {
        System.loadLibrary("hiacs");
    }
    public native void onServiceConnected(IBinder binder);
    public native void onServiceDisconnected();
    public native void operation(int command);
}
