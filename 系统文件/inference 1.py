from typing import Literal

from pydantic import BaseModel, Field


class ServiceInfo(BaseModel):
    """Public service capability contract for the system-foundation phase."""

    service: str
    version: str
    mode: Literal["not_deployed", "ready"]
    max_upload_bytes: int
    accepted_content_types: list[str]
    model_name: str | None = None
    classes: list[str] = Field(default_factory=list)
    device: str | None = None
    image_size: int | None = None
