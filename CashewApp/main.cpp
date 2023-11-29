//
// Created by sohaibalam on 27/11/23.
//

#include <CashewLib/Application.h>
#include <CashewLib/EntryPoint.h>

#include <CashewLib/Image.h>
#include <iomanip>

#include <CashewLib/Input/Input.h>
#include <CashewLib/Input/KeyCodes.h>

class ExampleLayer : public Cashew::Layer {
public:
  virtual void onUIRender() override {
    ImGui::Begin("Hello");
    ImGui::Button("Button");
    ImGui::End();

    ImGui::ShowDemoWindow();
  }
  // add input handling
  virtual void onUpdate(float dt) override {
    if (Cashew::Input::isKeyDown(Cashew::KeyCode::Tab))
      std::cout << "Tab key is pressed" << std::endl;
    else if (Cashew::Input::isKeyDown(Cashew::KeyCode::Escape)) {
      // exit the Application
    }
  }
};

Cashew::Application *Cashew::CreateApplication(int argc, char **argv) {
  Cashew::ApplicationSpecification spec;
  spec.Name = "Cashew Example";

  Cashew::Application *app = new Cashew::Application(spec);
  app->PushLayer<ExampleLayer>();
  app->SetMenubarCallback([app]() {
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("Exit")) {
        app->Close();
      }
      ImGui::EndMenu();
    }
  });
  return app;
}
