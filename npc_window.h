#pragma once

#include "document.h"

bool* show_npc_window_state();

void draw_npc_window();

class npc_document : public document
{
public:
	npc_document();
	~npc_document();
	bool save();
	bool create_new();
	bool open();
};