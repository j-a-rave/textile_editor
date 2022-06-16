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

static void save_as(document* doc)
{
	doc->filepath = dialog_save(doc->filter.data());
	doc->save();
}

static void file_menu(document* active_doc)
{
	if (active_doc == nullptr) {
		return;
	}

	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("New")) {
			active_doc->create_new();
		}
		if (ImGui::MenuItem("Open...")) {
			dialog_open();
		}

		ImGui::BeginDisabled(active_doc->dirty == false);

		if (ImGui::MenuItem("Save")) {
			if (active_doc->filepath.empty()) {
				save_as(active_doc);
			} else {
				active_doc->save();
			}
		}

		ImGui::EndDisabled();

		if (ImGui::MenuItem("Save As...")) {
			save_as(active_doc);
		}

		ImGui::EndMenu();
	}
}