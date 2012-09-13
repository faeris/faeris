#include"xirscript/xir_scanner.h"
#include"xirscript/xir_token.h"
#include"xirscript/sl_state.h"
#include<stdio.h>
#include"util/marocs.h"
#include<string>

XirScanner::XirScanner(IFile* file,XirState* begin_state)
{
	m_file=new XirFile(file);
	m_begin_state=begin_state;
	m_cur_token=XT_UNKOWN;
	m_cur_line=1;
}
XirScanner::~XirScanner()
{
	if(m_file)
	{
		delete m_file;
		m_file=NULL;
	}
}

int XirScanner::nextToken()
{
	XirFile* file=m_file;
	int line=m_cur_line;

	int finally_line;

	XirState* cur_state=m_begin_state;
	XirState* next_state=NULL;
	XirState* finnal_state=NULL;
	int finnal_token_size=0;

	int token_size=0;

	m_cur_string.clear();

	while(1)
	{
		char event=file->nextChar();
		if(event==EOF)
		{
			if(token_size==0)
			{
				m_cur_token=XT_EOF;
				break;
			}
			if(finnal_state==NULL)
			{
				file->mark();
				m_cur_token=XT_ERROR;
			}
			else
			{
				m_cur_token=finnal_state->token;
			}
			break;
		}

		token_size++;
		m_cur_string.append(1,event);
		if(event=='\n')
		{
			line++;
		}
		next_state=cur_state->next(event);
		if(next_state==&Err_State)
		{
			if(finnal_state==NULL)
			{
				m_cur_token=XT_ERROR;
				file->mark();
//				DEBUG("Error Translate %s(%c)",cur_state->name,event);
			}
			else
			{
				m_cur_token=finnal_state->token;

			}
			break;
		}

		if(next_state->isFinnally())
		{
			finnal_state=next_state;
			file->mark();
			finnal_token_size=token_size;
			finally_line=line;
		}
		cur_state=next_state;
	}
	if(m_cur_token!=XT_ERROR&&m_cur_token!=XT_EOF)
	{
		m_cur_string.resize(finnal_token_size);
		m_cur_line=finally_line;
	}
	else
	{
		m_cur_line=line;
	}
	file->ForwardToMark();
	return m_cur_token;
}

static const char* s_xir_token_name[]=
{
	"XT_UNKOWN",
	"XT_EOF",
	"XT_ERROR",
	"XT_SIM_STR",
	"XT_DOU_STR",
	"XT_SIN_STR",
	"XT_WS",
	"XT_COMMENT",
	"XT_NEWLINE",
	"XT_COMMA",
	"XT_COLON",
	"XT_AMPERSAND",
	"XT_DOLLAR",
	"XT_L_RB",
	"XT_R_RB",
	"XT_L_SB",
	"XT_R_SB",
};

std::string XirScanner::curTokenName()
{
	return std::string(s_xir_token_name[m_cur_token]);
}

















