package com.amaze.filemanager;

import androidx.test.core.app.ApplicationProvider;

import junit.framework.TestCase;

import org.junit.Before;
import org.junit.Test;

public class MinusTest extends TestCase {

    private MyTest mytest;

    @Before
    public void setUp() {
        mytest = new MyTest();
    }

    @Test
    public void testMinus1() throws Exception {
        assertEquals(2,mytest.minus(3,1));
    }

    @Test
    public void testMinus2() throws Exception {
        assertEquals(2,mytest.minus(4,1));
    }
}