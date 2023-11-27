//
// Created by sohaibalam on 27/11/23.
//

#include <Application.h>
#include <EntryPoint.h>


class ExampleLayer : public Cashew::Layer
{
public:
    virtual void onUIRender() override
    {
        ImGui::Begin("Hello");
        ImGui::Button("Button");
        ImGui::End();

        ImGui::ShowDemoWindow();
    }
};

Cashew::Application* Cashew::CreateApplication(int argc, char** argv)
{
    Cashew::ApplicationSpecification spec;
    spec.Name = "Cashew Example";

    Cashew::Application* app = new Cashew::Application(spec);
    app->PushLayer<ExampleLayer>();
    app->SetMenubarCallback([app]()
                            {
                                if (ImGui::BeginMenu("File"))
                                {
                                    if (ImGui::MenuItem("Exit"))
                                    {
                                        app->Close();
                                    }
                                    ImGui::EndMenu();
                                }
                            });
    return app;
}
