package com.example.myapplication.uistu.viewstu.customizeview.way1;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;

import com.example.myapplication.R;

public class MyView  extends View{
    public final String TAG = getClass().getName();
    private int width;
    private int height;
    private int defaultSize=100;

    public MyView(Context context){
        super(context);
    }

    public MyView(Context context, AttributeSet attrs){
        super(context, attrs);
        //第二个参数就是我们在styles.xml文件中的<declare-styleable>标签
        //即属性集合的标签，在R文件中名称为R.styleable+name
        TypedArray a = context.obtainStyledAttributes(attrs, R.styleable.MyView);

        //第一个参数为属性集合里面的属性，R文件名称：R.styleable+属性集合名称+下划线+属性名称
        //第二个参数为，如果没有设置这个属性，则设置的默认的值
        defaultSize = a.getDimensionPixelSize(R.styleable.MyView_default_size, defaultSize);

        //最后记得将TypedArray对象回收
        a.recycle();
    }

    private int getMySize(int defaultSize, int measureSpec){
        int mySize = defaultSize;
        int mode = MeasureSpec.getMode(measureSpec);
        //!!!!mmb
        //这里有坑， heightMeasureSpec里面的类型呈奇偶变化，第一次1810, 第二次就会变成275
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
                default:
                    break;
        }
        return mySize;
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec){

        width = getMySize(defaultSize, widthMeasureSpec);
         height = getMySize(defaultSize, heightMeasureSpec);
        //Log.v(TAG, "onMeasure, my width: " + width + "myHeight: " + height);

        if(width<height){
            height = width;
        }else {
            width = height;
        }

        //问了专门做ui的同事，直接赋值是最好的
        width = 275;
        height = 275;
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
