package com.hikvision.aidlservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

import com.hikvision.HiAcs;

public class MyService extends Service {
    private static final String TAG = "MyService";
    private IBinder mBinder;
    HiAcs hiAcs;

    @Override
    public void onCreate()
    {
        super.onCreate();
        hiAcs = new HiAcs();
        mBinder = hiAcs.createServiceBinder();

        if(null == mBinder)
        {
            Log.w(TAG, "[MyService] [java] Binder is null");
        }
        else
        {
            Log.d(TAG, "[MyService] [java] Binder is ready");
        }
    }


    @Override
    public IBinder onBind(Intent intent)
    {
        Log.d(TAG, "[MyService] [java] A client binds the service");

        return mBinder;
    }

}
