//
// Created by sohaibalam on 29/11/23.
//

#ifndef CASHEWAPP_IMAGE_H
#define CASHEWAPP_IMAGE_H

#include <string>
#include "vulkan/vulkan.h"

namespace Cashew {

    enum class ImageFormat
    {
        None = 0,
        RGBA,
        RGBA32F,
    };

    class Image {
    public:
        Image(std::string_view path);
        Image(uint32_t width, uint32_t height, ImageFormat format, const void* data = nullptr);
        ~Image();

        void setData(const void* data);

        VkDescriptorSet getDescriptorSet() const { return m_DescriptorSet; }
        void resize(uint32_t width, uint32_t height);

        uint32_t getWidth() const { return m_Width; }
        uint32_t getHeight() const { return m_Height; }


    private:
    void AllocateMemory(uint64_t size);
    void Release();
    private:
    uint32_t m_Width = 0, m_Height = 0;

    VkImage m_Image = nullptr;
    VkImageView m_ImageView = nullptr;
    VkDeviceMemory m_Memory = nullptr;
    VkSampler m_Sampler = nullptr;

    ImageFormat m_Format = ImageFormat::None;

    VkBuffer m_StagingBuffer = nullptr;
    VkDeviceMemory m_StagingBufferMemory = nullptr;

    size_t m_AlignedSize = 0;

    VkDescriptorSet m_DescriptorSet = nullptr;

    std::string m_Filepath;
    };


} // Cashew

#endif //CASHEWAPP_IMAGE_H
