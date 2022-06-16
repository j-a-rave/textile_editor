#include "npc_window.h"

#include "imgui_helper.h"
#include "npc.h"

#include <vector>

static bool Show_npc_window = false;

static std::vector<textile::npc> npcs;

static npc_document* active_npc_doc = new npc_document();

// internal functions -------------------------------


void create_new_active_npc_doc()
{
	if (active_npc_doc != nullptr) {
		delete(active_npc_doc);
	}

	active_npc_doc = new npc_document();
}

// npc_document class functions ---------------------

npc_document::npc_document()
{
	extension = "npc";
	filter = L"NPC files (*.npc)\0*.npc\0All Files(*.*)\0*.*\0";
	dirty = false;
}

npc_document::~npc_document()
{
	if (dirty) {
		// TODO ask to save data before destroying
		// or rather, would probably be better to have a 'cancel' option
		// so... maybe don't check for this in the destructor after all?
	}
}


bool npc_document::save()
{
	// TODO
	return true;
}

bool npc_document::create_new()
{
	create_new_active_npc_doc();
	return true;
}

bool npc_document::open()
{
	// TODO
	return true;
}


// nonmember functions ------------------------------

bool* show_npc_window_state()
{
	return &Show_npc_window;
}

void draw_npc_window()
{

	if (!Show_npc_window) {
		return;
	}

	ImGui::Begin("NPC", &Show_npc_window, ImGuiWindowFlags_MenuBar);

    if (ImGui::BeginMenuBar())
    {
		file_menu(active_npc_doc);
        ImGui::EndMenuBar();
    }

	if (ImGui::Button("Add dummy entry")) {
		std::string dummy_id = "dummy_" + std::to_string(npcs.size());
		npcs.emplace_back(dummy_id);
	}
	for (textile::npc &n : npcs) {
		if (ImGui::TreeNode(n.sys_id.data())) {
			loc_string_input_text(n.display_name);
			ImGui::TreePop();
		}
	}

	ImGui::End(); // NPC
}