#ifndef _FAERY_XIR_SCRIPT_XIR_AST_H_
#define _FAERY_XIR_SCRIPT_XIR_AST_H_
#include<vector>
#include"FsMacros.h"
#include<string>
class XirAstNode
{
	public:
		enum XirAstNodeType
		{
			AT_ROOT,
			AT_REF_DICT,
			AT_DICT,
			AT_ARRAY,
			AT_STRING,
			AT_DICT_ENTRY,
			AT_REFER,
		};
		enum DemiliterType
		{
			DT_NEWLINE,
			DT_COMMA,
		};
	public:
		int m_line;
	public:
		XirAstNode(int line)
		{
			m_line=line;
		}
		virtual void deleteSelf()=0;
		virtual int getType()=0;
		virtual ~XirAstNode(){}
};

class XirAstStringNode:public XirAstNode
{
	public:
		std::string m_value;
	public:
		XirAstStringNode(const std::string& val,int line)
			:XirAstNode(line)
		{
			m_value=val;
		}
		void setString(const std::string& val)
		{
			m_value=val;
		}
		std::string getString()
		{
			return m_value;
		}
		virtual int getType()
		{
			return AT_STRING;
		}
		virtual void deleteSelf()
		{
			delete this;
		}
};
class XirAstReferNode:public XirAstNode
{
	public:
		std::string m_value;
	public:
		XirAstReferNode(const std::string& val,int line)
			:XirAstNode(line)
		{
			m_value=val;
		}
		void setString(const std::string& val)
		{
			m_value=val;
		}
		std::string getString()
		{
			return m_value;
		}
		virtual int getType()
		{
			return AT_REFER;
		}
		virtual void deleteSelf()
		{
			delete this;
		}
};

class XirAstComplexNode:public XirAstNode
{
	public:
		std::vector<XirAstNode*> m_chirldren;
		int m_type;
	public:
		XirAstComplexNode(int type,int line)
			:XirAstNode(line)
		{
			m_type=type;
		}
		virtual int getType()
		{
			return m_type;
		}
		void setType(int type)
		{
			m_type=type;
		}
		void addChrild(XirAstNode* node)
		{
			m_chirldren.push_back(node);
		}
		void dropChirldren()
		{
			m_chirldren.clear();
		}
		void deleteChirldren()
		{
			std::vector<XirAstNode*>::iterator i;
			for(i=m_chirldren.begin();i!=m_chirldren.end();++i)
			{
				delete *i;
			}
			m_chirldren.clear();
		}

		int getChirldNum()
		{
			return m_chirldren.size();
		}
		XirAstNode* getChirld(unsigned long index)
		{
			FS_TRACE_ERROR_ON(index>=m_chirldren.size(),"Invalid Index");
			return m_chirldren[index];
		}

		~XirAstComplexNode()
		{
			deleteChirldren();
		}
		virtual void deleteSelf()
		{
			dropChirldren();
			delete this;
		}
};

void XirAstNode_Print(XirAstNode* node,int demiliter,bool indent);
int XirAstNode_Check(XirAstNode* node);


#endif /*_FAERY_XIR_SCRIPT_XIR_AST_H_*/



