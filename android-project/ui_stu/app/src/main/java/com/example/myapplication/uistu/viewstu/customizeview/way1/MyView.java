package com.example.myapplication.uistu.viewstu.customizeview.way1;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;

public class MyView  extends View{
    public final String TAG = getClass().getName();
    private int width;
    private int height;

    public MyView(Context context){
        super(context);
    }

    public MyView(Context context, AttributeSet attrs){
        super(context, attrs);
    }

    private int getMySize(int defaultSize, int measureSpec){
        int mySize = defaultSize;
        int mode = MeasureSpec.getMode(measureSpec);
        int size = MeasureSpec.getSize(measureSpec);

        switch (mode){
            case MeasureSpec.UNSPECIFIED: //如果没有指定大小，就设置为默认大小
                mySize = defaultSize;
                break;
            case MeasureSpec.AT_MOST:  //如果测量模式是最大取值为size
                //我们将大小取最大值,你也可以取其他值
                mySize = size;
                break;
            case MeasureSpec.EXACTLY: //如果是固定的大小，那就不要去改变它
                mySize = size;
                //mySize = defaultSize;
                break;
        }
        return mySize;
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec){

        width = getMySize(100, widthMeasureSpec);
         height = getMySize(100, heightMeasureSpec);
        Log.v(TAG, "onMeasure, my width: " + width + "myHeight: " + height);

        if(width<height){
            height = width;
        }else {
            width = height;
        }
        //这里很奇怪，这样写可以。如果不写width=275，它就是满屏的。虽然width的值是正确的。
        width=275;
        Log.v(TAG, "onMeasure, final----my width: " + width + "myHeight: " + height);
        widthMeasureSpec = MeasureSpec.makeMeasureSpec(width, MeasureSpec.getMode(widthMeasureSpec));
        heightMeasureSpec = MeasureSpec.makeMeasureSpec(height, MeasureSpec.getMode(heightMeasureSpec));
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);
        setMeasuredDimension(width, height);
    }

    @Override
    protected void onDraw(Canvas canvas){
        super.onDraw(canvas);
        int r = getMeasuredWidth()/2;
        int centerX = getLeft()+r;
        int centerY = getTop()+r;
        Paint paint = new Paint();
        paint.setColor(Color.GREEN);
        canvas.drawCircle(centerX, centerY, r, paint);
    }
}
