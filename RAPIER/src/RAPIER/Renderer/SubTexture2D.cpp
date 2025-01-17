#include "rppch.h"
#include "SubTexture2D.h"

namespace RAPIER
{
	SubTexture2D::SubTexture2D(const Ref<Texture2D>& texture, const glm::vec2& min, const glm::vec2& max)
		: m_Texture(texture)
	{
		RP_PROFILE_RENDERER_FUNC();

		m_TexCoords[0] = { min.x, min.y };
		m_TexCoords[1] = { max.x, min.y };
		m_TexCoords[2] = { max.x, max.y };
		m_TexCoords[3] = { min.x, max.y };
	}

	Ref<SubTexture2D> SubTexture2D::CreateFromCoords(const Ref<Texture2D>& texture, const glm::vec2& coords, const glm::vec2& spriteSize)
	{
		RP_PROFILE_RENDERER_FUNC();

		uint32_t AddX = 1;
		uint32_t AddY = spriteSize.y / spriteSize.x;
		if (AddY == 0)
		{
			AddX = spriteSize.x / spriteSize.y;
			if (AddX == 0)
			{
				AddX = 1;
				AddY = 1;
			}
		}
		glm::vec2 min = { (coords.x * (spriteSize.x / AddX)) / texture->GetWidth(), (coords.y * (spriteSize.y / AddY)) / texture->GetHeight() };
		glm::vec2 max = { ((coords.x + AddX) * (spriteSize.x / AddX)) / texture->GetWidth(), ((coords.y + AddY) * (spriteSize.y / AddY)) / texture->GetHeight() };
		return Ref<SubTexture2D>::Create(texture, min, max);
	}

}	//	END namespace RAPIER
