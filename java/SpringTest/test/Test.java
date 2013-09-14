package test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

import service.radCheckService;
import bean.radCheckBean;



public class Test {

	private static radCheckService radCheckService;
	
	public static void main(String[] args) {
		ApplicationContext ac = new FileSystemXmlApplicationContext("src/applicationContext.xml"); 
		radCheckService = (radCheckService) ac.getBean("radCheckService"); 
		radCheckBean radCheck =  radCheckService.getRadCheckBean();
		if (radCheck != null) {
			System.out.println("---------" + radCheck.getUsername());
		}
	}

}
