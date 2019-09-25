#pragma once
#include "Camera.hpp"
#include "CameraView.hpp"

class View
{
private:
    Camera camera{};
    CameraView camera_view{};
    matrix3 ndc_matrix;
public:
    void Init();
    void Update(float dt);

    Camera& Get_Camera()
    {
        return camera;
    }
    CameraView& Get_Camera_View()
    {
        return camera_view;
    }
    matrix3 Get_Ndc_Matrix()
    {
        return ndc_matrix;
    }


};