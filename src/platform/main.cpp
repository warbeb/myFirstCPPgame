#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

#include <gameMain.h>
int main()
{

#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE);
#endif


	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "window name");
	SetExitKey(KEY_NULL);
	SetTargetFPS(240);

#pragma region imgui
	rlImGuiSetup(true);

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; 
	io.FontGlobalScale = 2; //Change the scale for ImGui IO

	//ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();
	ImGui::StyleColorsClassic();

	if (!initGame())
	{
		return 0;
	}


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		
#pragma region imgui
		rlImGuiBegin();

		//Docking stuff...
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);


		if (!updateGame())
		{
			CloseWindow();
		}
	
	#pragma region imgui
		rlImGuiEnd();

	#pragma endregion

		EndDrawing();
	}
	CloseWindow();

	closeGame();
#pragma region imgui
	rlImGuiShutdown();
#pragma endregion

	return 0;
}