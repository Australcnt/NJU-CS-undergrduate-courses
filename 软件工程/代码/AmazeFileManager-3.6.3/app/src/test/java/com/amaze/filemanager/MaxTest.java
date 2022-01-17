package com.amaze.filemanager;

import junit.framework.TestCase;

import org.junit.Before;
import org.junit.Test;

public class MaxTest extends TestCase {

    private MyTest mytest;

    @Before
    public void setUp() {
        mytest = new MyTest();
    }

    @Test
    public void testMax1() throws Exception {
        assertEquals(3,mytest.max(3,1));
    }

    @Test
    public void testMax2() throws Exception {
        assertEquals(3,mytest.max(2,1));
    }
}