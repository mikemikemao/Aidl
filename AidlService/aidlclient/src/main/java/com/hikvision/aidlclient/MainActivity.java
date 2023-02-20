package com.hikvision.aidlclient;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.ConditionVariable;
import android.os.IBinder;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.hikvision.HiAcs;
import com.hikvision.common.Common;

public class MainActivity extends AppCompatActivity implements ServiceConnection {
    private static final String TAG = Common.LOG_TAG;
    private volatile boolean mIsServiceConnected = false;
    private final ConditionVariable mServiceConnectionWaitLock = new ConditionVariable();
    private Button btTest;
    HiAcs hiAcs;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        hiAcs = new HiAcs();
    }

    protected void onResume() {
        super.onResume();
        initView();
        bindService();
    }


    private void initView() {
        btTest = findViewById(R.id.test);

        btTest.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                hiAcs.operation(1);
            }
        });
    }

    /**
     * 绑定服务
     */
    private void bindService() {
        Intent intent = new Intent();
        intent.setClassName("com.hikvision.aidlservice","com.hikvision.aidlservice.MyService");
        boolean ret = bindService(intent, this, Context.BIND_AUTO_CREATE);
        Log.d(TAG, "bindService: ret = "+ ret);
        new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                runOnUiThread(new SetTextRunnable("Waiting to talk to IMyService..."));
                // Not connected to service yet?
                while(!mIsServiceConnected)
                {
                    mServiceConnectionWaitLock.block(); // waits for service connection
                }

                runOnUiThread(new SetTextRunnable("Talked to IMyService. Returned : .............." ));
            }
        }).start();
    }

    private class SetTextRunnable implements Runnable
    {
        final String mText;

        SetTextRunnable(String text)
        {
            mText = text;
        }

        @Override
        public void run()
        {
            Log.d(TAG, mText);
        }
    }

    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
        Log.d(TAG, "[App] [java] onServiceConnected");
        hiAcs.onServiceConnected(service);
        mIsServiceConnected = true;
        mServiceConnectionWaitLock.open(); // breaks service connection waits
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {
        mIsServiceConnected = false;
        hiAcs.onServiceDisconnected();
        Log.d(TAG, "[App] [java] onServiceDisconnected");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mIsServiceConnected = false;
        hiAcs.onServiceDisconnected();
    }
}