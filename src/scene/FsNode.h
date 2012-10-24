#ifndef _FAERIS_NODE_H_
#define _FAERIS_NODE_H_
#include "graphic/FsRenderable.h"
#include "FsAction.h"

FAERIS_NAMESPACE_BEGIN
class Render;
class Node:public Renderable
{

	public:
		Node();
		Node(Renderable* ob);
		virtual ~Node();
		void attach(Renderable* ob);
	public:
		void doAction(const FsAction& action);
		void pause();	/* suspend  the execution of actions */
		void resume();	/* resumes the execution of actions */
		void stop();	/* removes all actions from the running action list */

		virtual void onEnter();	/* node enter the state */
		virtual void onExit();  /* node exits the stage */

		void kill();	/* remode the object from its parent */

		virtual void draw(Render* );


	protected:
		void drawBegin(Render* );
		void drawEnd(Render* );

	private:
		Renderable* m_ob;

};

FAERIS_NAMESPACE_END

#endif 

