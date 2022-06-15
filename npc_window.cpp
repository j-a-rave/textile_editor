#include "npc_window.h"

#include "imgui_helper.h"
#include "npc.h"

#include <vector>

static bool Show_npc_window = false;

static std::vector<textile::npc> npcs;

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
		// TODO pass active document, if any
		file_menu(nullptr);
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