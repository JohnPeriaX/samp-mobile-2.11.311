//
// Created on 25.04.2024.
//

#include "gta-reversed/game_sa/Fx/CarFXRenderer.h"
#include "gta-reversed/game_sa/Pipelines/CustomCar/CustomCarEnvMapPipeline.h"

/* เพิ่มจาก sasamp-main: CCarFXRenderer::Initialise */
bool CCarFXRenderer::Initialise()
{
    return CCustomCarEnvMapPipeline::CreatePipe() != 0;
}
