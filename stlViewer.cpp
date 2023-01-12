#include "stlViewer.h"

CustomInteractorStyle::CustomInteractorStyle()
{
    LastPickedActor = NULL;
}
CustomInteractorStyle::~CustomInteractorStyle()
{

}

void CustomInteractorStyle::OnRightButtonDown()
{   
    __super::OnLeftButtonDown();
}

void CustomInteractorStyle::OnRightButtonUp()
{
    __super::OnLeftButtonUp();
}

void CustomInteractorStyle::OnLeftButtonDown()
{
    printf("leftButton");

    //int* clickPos = this->GetInteractor()->GetEventPosition();

    //// Pick from this location.
    //vtkNew<vtkPropPicker> picker;
    //picker->Pick(clickPos[0], clickPos[1], 0, this->GetDefaultRenderer());

    //// If we picked something before, reset its property
    //if (LastPickedActor)
    //{
    //    LastPickedActor->GetProperty()->DeepCopy();
    //}
    //LastPickedActor = picker->GetActor();
    //if (LastPickedActor)
    //{
    //    // Save the property of the picked actor so that we can
    //    // restore it next time
    //    LastPickedProperty->DeepCopy(LastPickedActor->GetProperty());
    //    // Forward events
    //    vtkInteractorStyleTrackballCamera::OnLeftButtonDown();

    }



void CustomInteractorStyle::OnLeftButtonUp()
{
    printf("222222222222222222");

}

