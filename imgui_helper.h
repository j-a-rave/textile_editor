#pragma once

// Collection of helper classes and macros to make imgui code more readable.

#include "imgui_stdlib.h"
#include "loc_string.h"
#include "file_dialog.h"
#include "document.h"


static void loc_string_input_text(textile::loc_string &ls)
{
	for (char i = 0; i < textile::LANGUAGE::NUM_LANGUAGES; i++) {
		ImGui::InputText(textile::get_language_label((textile::LANGUAGE)i).data(),
			ls.get_localized_value());
	}
}

static void file_menu(document* active_doc)
{
	// TODO call active_doc event for listeners
	// ALSO TODO make a listener for such a thing, should each type of document have a manager which listens for it?
	// should that be separate from the npc_window code that displays them? (yes)
	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("New")) {
			dialog_open();
		}
		if (ImGui::MenuItem("Open...")) {
			dialog_open();
		}

		ImGui::BeginDisabled(active_doc == nullptr);

		if (ImGui::MenuItem("Save")) {
			dialog_save();
		}
		if (ImGui::MenuItem("Save As...")) {
			dialog_save();
		}

		ImGui::EndDisabled();

		ImGui::EndMenu();
	}
}