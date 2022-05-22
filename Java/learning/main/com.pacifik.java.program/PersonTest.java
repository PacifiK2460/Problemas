package com.pacifik.java.program;

import org.junit.Test;
import org.junit.Assert.assertEquals;

public class PersonTest{
	@Test
	public void returnHelloWorld(){
		Person marcus = new Person();
		assertEquals("Hello World",marcus.helloWorld);
	}
}

