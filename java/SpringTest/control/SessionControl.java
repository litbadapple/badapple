package control;

import java.sql.SQLException;
import java.util.ArrayList;

import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;

public class SessionControl {
	private ArrayList sessionFactoryList;
	private SessionFactory activeFactory;
	
	public ArrayList getSessionFactoryList() {
		return sessionFactoryList;
	}
	public void setSessionFactoryList(ArrayList sessionFactoryList) {
		this.sessionFactoryList = sessionFactoryList;
	}
	public SessionFactory getActiveFactory() {
		for (int i = 0; i < this.sessionFactoryList.size(); i++) {
			activeFactory =(SessionFactory) sessionFactoryList.get(i);
			Session session = activeFactory.openSession();
			try {
				if (session.connection().isClosed()) {
					System.out.println("*******************Connnect is closed");
				} else {
					System.out.println("*******************Connnect is connected");
				}
			} catch (HibernateException e) {
				// TODO Auto-generated catch block
				System.out.println("******************Connnect is closed");
				e.printStackTrace();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				System.out.println("********************Connnect is closed");
				e.printStackTrace();
			}
		}
		return activeFactory;
	}

}
