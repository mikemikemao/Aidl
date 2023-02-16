package com.hikvision.aidlclient;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.hikvision.aidlservice.IMyAidlInterface;

public class MainActivity extends AppCompatActivity implements ServiceConnection{
    private static final String TAG = "MainActivity";
    private IMyAidlInterface iMyAidlInterface;
    private ServiceConnection serviceConnection;
    private Button btAdd, btMinus, btGet;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

//        try {
//            int res = iMyAidlInterface.add(2, 2);
//            Log.d(TAG, "add: " + res);	//add:4
//        } catch (RemoteException e) {
//            e.printStackTrace();
//        }
    }

    protected void onResume() {
        super.onResume();
        initView();
        bindService();
    }


    private void initView() {
        btAdd = findViewById(R.id.add);
        btMinus = findViewById(R.id.min);


        btAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    int res = iMyAidlInterface.add(2, 2);
                    Log.d(TAG, "add: " + res);	//add:4
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
            }
        });
        btMinus.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    int res = iMyAidlInterface.minus(9, 2);
                    Log.d(TAG, "minus: " + res); //minus:7
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
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
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        unbindService(serviceConnection);
    }

    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
        Log.d(TAG, "onServiceConnected: ");
        iMyAidlInterface = IMyAidlInterface.Stub.asInterface(service);
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {
        Log.d(TAG, "onServiceDisconnected: ");
        iMyAidlInterface = null;
    }
}