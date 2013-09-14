package service;

import java.util.List;

import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

import bean.radCheckBean;

public class radCheckService extends HibernateDaoSupport{
	
	public radCheckBean getRadCheckBean(){
		this.getHibernateTemplate().getSessionFactory();		
		/*
		if (this.getHibernateTemplate().getSessionFactory().getCurrentSession().isConnected()) {
			System.out.println("session is connected");
			this.getHibernateTemplate().getSessionFactory().openSession().close();
		} else {
			System.out.println("session is close");
		}
		*/
		
		List<radCheckBean> list = this.getHibernateTemplate().find("from radCheckBean");
		
		return list.get(0);
	}
	
}
